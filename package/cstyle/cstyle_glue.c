/****************************************************************************
 * Copyright (c) 2012, the Konoha project authors. All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ***************************************************************************/

/* ************************************************************************ */

#include <minikonoha/minikonoha.h>
#include <minikonoha/sugar.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Expression */

static KMETHOD Statement_while(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Statement(stmt, gma);
	DBG_P("while statement .. ");
	int ret = false;
	if(SUGAR kStmt_tyCheckByName(kctx, stmt, KW_ExprPattern, gma, TY_boolean, 0)) {
		kBlock *bk = SUGAR kStmt_getBlock(kctx, stmt, NULL/*DefaultNameSpace*/, KW_BlockPattern, K_NULLBLOCK);
		kStmt_set(CatchContinue, stmt, true);  // set before tyCheckAll
		kStmt_set(CatchBreak, stmt, true);
		ret = SUGAR kBlock_tyCheckAll(kctx, bk, gma);
		if(ret) {
			kStmt_typed(stmt, LOOP);
		}
	}
	KReturnUnboxValue(ret);
}

static KMETHOD Statement_do(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Statement(stmt, gma);
	DBG_P("do statement .. ");
	int ret = false;
	if(SUGAR kStmt_tyCheckByName(kctx, stmt, KW_ExprPattern, gma, TY_boolean, 0)) {
		kBlock *bk = SUGAR kStmt_getBlock(kctx, stmt, NULL/*DefaultNameSpace*/, KW_BlockPattern, K_NULLBLOCK);
		kStmt_set(CatchContinue, stmt, true);  // set before tyCheckAll
		kStmt_set(CatchBreak, stmt, true);
		ret = SUGAR kBlock_tyCheckAll(kctx, bk, gma);
		if(ret) {
			kStmt_typed(stmt, LOOP);  // FIXME
		}
	}
	KReturnUnboxValue(ret);
}

static KMETHOD Statement_CStyleFor(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Statement(stmt, gma);
	DBG_P("for statement .. ");
	int ret = false;
	if(SUGAR kStmt_tyCheckByName(kctx, stmt, KW_ExprPattern, gma, TY_boolean, 0)) {
		kBlock *bk = SUGAR kStmt_getBlock(kctx, stmt, NULL/*DefaultNameSpace*/, KW_BlockPattern, K_NULLBLOCK);
		kStmt_set(CatchContinue, stmt, true);  // set before tyCheckAll
		kStmt_set(CatchBreak, stmt, true);
		ret = SUGAR kBlock_tyCheckAll(kctx, bk, gma);
		if(ret) {
			kStmt_typed(stmt, LOOP);
		}
	}
	KReturnUnboxValue(ret);
}

static inline kStmt* kStmt_getParentNULL(kStmt *stmt)
{
	return stmt->parentBlockNULL->parentStmtNULL;
}

static KMETHOD Statement_break(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Statement(stmt, gma);
	kStmt *p = stmt;
	while((p = kStmt_getParentNULL(p)) != NULL) {
		if(kStmt_is(CatchBreak, p)) {
			KLIB kObject_setObject(kctx, stmt, stmt->syn->keyword, TY_Stmt, p);
			kStmt_typed(stmt, JUMP);
			KReturnUnboxValue(true);
		}
	}
	SUGAR kStmt_printMessage2(kctx, stmt, NULL, ErrTag, "break statement not within a loop");
}

static KMETHOD Statement_continue(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Statement(stmt, gma);
	kStmt *p = stmt;
	while((p = kStmt_getParentNULL(p)) != NULL) {
		if(kStmt_is(CatchContinue, p)) {
			KLIB kObject_setObject(kctx, stmt, stmt->syn->keyword, TY_Stmt, p);
			kStmt_typed(stmt, JUMP);
			KReturnUnboxValue(true);
		}
	}
	SUGAR kStmt_printMessage2(kctx, stmt, NULL, ErrTag, "continue statement not within a loop");
}

/* Literal */

static KMETHOD TokenFunc_SingleQuotedChar(KonohaContext *kctx, KonohaStack *sfp)
{
	kTokenVar *tk = (kTokenVar *)sfp[1].asObject;
	int ch, prev = '/', pos = 1;
	const char *source = S_text(sfp[2].asString);
	while((ch = source[pos++]) != 0) {
		if(ch == '\n') {
			break;
		}
		if(ch == '\'' && prev != '\\') {
			if(IS_NOTNULL(tk)) {
				KFieldSet(tk, tk->text, KLIB new_kString(kctx, OnField, source + 1, (pos-2), 0));
				tk->unresolvedTokenType = SYM_("$SingleQuotedChar");
			}
			KReturnUnboxValue(pos);
		}
		prev = ch;
	}
	if(IS_NOTNULL(tk)) {
		SUGAR kToken_printMessage(kctx, tk, ErrTag, "must close with %s", "'");
	}
	KReturnUnboxValue(0);
}

static KMETHOD TypeCheck_SingleQuotedChar(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_TypeCheck(stmt, expr, gma, reqty);
	kToken *tk = expr->termToken;
	if(S_size(tk->text) == 1) {
		int ch = S_text(tk->text)[0];
		KReturn(SUGAR kExpr_setUnboxConstValue(kctx, expr, TY_int, ch));
	}
	else if(S_size(tk->text) == 2) {
		int ch = S_text(tk->text)[0];
		if(ch == '\\') {
			ch = S_text(tk->text)[1];
			switch(ch) {
			case '\'': ch = '\''; break;
			case '\\': ch = '\\'; break;
			case 'b':  ch = '\b'; break;
			case 'f':  ch = '\f'; break;
			case 'n':  ch = '\n'; break;
			case 'r':  ch = '\r'; break;
			case 't':  ch = '\t'; break;
			default:
				KReturn(K_NULLEXPR);
			}
			KReturn(SUGAR kExpr_setUnboxConstValue(kctx, expr, TY_int, ch));
		}
	}
	KReturn(K_NULLEXPR);
}

/* Expression */

static KMETHOD Expression_Indexer(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Expression(stmt, tokenList, beginIdx, operatorIdx, endIdx);
	KonohaClass *genericsClass = NULL;
	kNameSpace *ns = Stmt_nameSpace(stmt);
	int nextIdx = SUGAR TokenUtils_parseTypePattern(kctx, ns, tokenList, beginIdx, endIdx, &genericsClass);
	if(nextIdx != -1) {  // to avoid Func[T]
		KReturn(SUGAR kStmt_parseOperatorExpr(kctx, stmt, tokenList->TokenItems[beginIdx]->resolvedSyntaxInfo, tokenList, beginIdx, beginIdx, endIdx));
	}
	DBG_P("beginIdx=%d, endIdx=%d", beginIdx, endIdx);
	kToken *currentToken = tokenList->TokenItems[operatorIdx];
	if(beginIdx < operatorIdx) {
		kExpr *leftExpr = SUGAR kStmt_parseExpr(kctx, stmt, tokenList, beginIdx, operatorIdx, NULL);
		if(leftExpr == K_NULLEXPR) {
			KReturn(leftExpr);
		}
		/* transform 'Value0 [ Value1 ]=> (Call Value0 get (Value1)) */
		kTokenVar *tkN = new_(TokenVar, 0, OnGcStack);
		tkN->resolvedSymbol= MN_toGETTER(0);
		tkN->uline = currentToken->uline;
		SugarSyntax *syn = SYN_(Stmt_nameSpace(stmt), KW_ExprMethodCall);
		leftExpr  = SUGAR new_UntypedCallStyleExpr(kctx, syn, 2, tkN, leftExpr);
		leftExpr = SUGAR kStmt_addExprParam(kctx, stmt, leftExpr, currentToken->subTokenList, 0, kArray_size(currentToken->subTokenList), "[");
		KReturn(SUGAR kStmt_rightJoinExpr(kctx, stmt, leftExpr, tokenList, operatorIdx + 1, endIdx));
	}
	DBG_P("nothing");
}

static KMETHOD Expression_Increment(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Expression(stmt, tokenList, beginIdx, operatorIdx, endIdx);
	DBG_P("beginIdx=%d, endIdx=%d", beginIdx, endIdx);
	kToken *currentToken = tokenList->TokenItems[operatorIdx];
	SugarSyntax *opSyntax = currentToken->resolvedSyntaxInfo;
	TokenSequence macro = {Stmt_nameSpace(stmt), tokenList};
	TokenSequence_push(kctx, macro);
	macro.TargetPolicy.RemovingIndent = true;
	if(beginIdx == endIdx) { /* ++A  MACRO    X X = (X) + 1 */
		MacroSet macroParam[] = {
			{SYM_("X"), tokenList, operatorIdx+1, endIdx},
			{0, NULL, 0, 0}, /* sentinel */
		};
		SUGAR TokenSequence_applyMacro(kctx, &macro, opSyntax->macroDataNULL_OnList, 0, 5, 1, macroParam);
	}
	else {/* (beginIdx < operatorIdx) MACRO ${ int _ = X; X = (X) + 1; _} */
		TokenSequence macro = {Stmt_nameSpace(stmt), tokenList};
		MacroSet macroParam[] = {
			{SYM_("X"), tokenList, beginIdx, operatorIdx},
			{0, NULL, 0, 0}, /* sentinel */
		};
		SUGAR TokenSequence_applyMacro(kctx, &macro, opSyntax->macroDataNULL_OnList, 5, kArray_size(opSyntax->macroDataNULL_OnList), 1, macroParam);
	}
	kExpr *expr = SUGAR kStmt_parseExpr(kctx, stmt, macro.tokenList, macro.beginIdx, macro.endIdx, NULL/*FIXME*/);
	TokenSequence_pop(kctx, macro);
	KReturn(expr);
}



static KMETHOD Int_opPlus(KonohaContext *kctx, KonohaStack *sfp)
{
	KReturnUnboxValue(+(sfp[0].intValue));
}

static KMETHOD Int_opCompl (KonohaContext *kctx, KonohaStack *sfp)
{
	KReturnUnboxValue(~sfp[0].intValue);
}

static KMETHOD Int_opLSHIFT (KonohaContext *kctx, KonohaStack *sfp)
{
	int lshift = sfp[1].intValue;
	KReturnUnboxValue(sfp[0].intValue << lshift);
}

static KMETHOD Int_opRSHIFT (KonohaContext *kctx, KonohaStack *sfp)
{
	int rshift = sfp[1].intValue;
	KReturnUnboxValue(sfp[0].intValue >> rshift);
}

static KMETHOD Int_opAND(KonohaContext *kctx, KonohaStack *sfp)
{
	KReturnUnboxValue(sfp[0].intValue & sfp[1].intValue);
}

static KMETHOD Int_opOR(KonohaContext *kctx, KonohaStack *sfp)
{
	KReturnUnboxValue(sfp[0].intValue | sfp[1].intValue);
}

static KMETHOD Int_opXOR(KonohaContext *kctx, KonohaStack *sfp)
{
	KReturnUnboxValue(sfp[0].intValue ^ sfp[1].intValue);
}

/* ------------------------------------------------------------------------ */

#define _Public   kMethod_Public
#define _Const    kMethod_Const
#define _Im       kMethod_Immutable
#define _Final    kMethod_Final
#define _F(F)   (intptr_t)(F)

static kbool_t int_defineMethod(KonohaContext *kctx, kNameSpace *ns, KTraceInfo *trace)
{
	int FN_x = FN_("x");
	KDEFINE_METHOD MethodData[] = {
		_Public|_Const|_Im, _F(Int_opPlus), TY_int, TY_int, MN_("+"), 0,
		_Public|_Const|_Im, _F(Int_opCompl), TY_int, TY_int, MN_("~"), 0,
		_Public|_Const|_Im, _F(Int_opLSHIFT), TY_int, TY_int, MN_("<<"), 1, TY_int, FN_x,
		_Public|_Const|_Im, _F(Int_opRSHIFT), TY_int, TY_int, MN_(">>"), 1, TY_int, FN_x,
		_Public|_Const|_Im, _F(Int_opAND), TY_int, TY_int, MN_("&"), 1, TY_int, FN_x,
		_Public|_Const|_Im, _F(Int_opOR ), TY_int, TY_int, MN_("|"), 1, TY_int, FN_x,
		_Public|_Const|_Im, _F(Int_opXOR), TY_int, TY_int, MN_("^"), 1, TY_int, FN_x,
		//_Public|_Const|_Im, _F(Int_opINC), TY_int, TY_int, MN_("opINC"), 0,
		//_Public|_Const|_Im, _F(Int_opDEC), TY_int, TY_int, MN_("opDEC"), 0,
		DEND,
	};
	KLIB kNameSpace_LoadMethodData(kctx, ns, MethodData, trace);
	KDEFINE_INT_CONST IntData[] = {
		{"INT_MAX", TY_int, KINT_MAX},
		{"INT_MIN", TY_int, KINT_MIN},
		{NULL},
	};
	KLIB kNameSpace_LoadConstData(kctx, ns, KonohaConst_(IntData), trace);
	return true;
}

// --------------------------------------------------------------------------
/* Syntax */

static char parseHexDigit(char c)
{
	return ('0' <= c && c <= '9') ? c - '0' :
		('a' <= c && c <= 'f') ? c - 'a' + 10:
		('A' <= c && c <= 'F') ? c - 'A' + 10:-1;
}
static char parseOctalDigit(char c)
{
	return ('0' <= c && c <= '7') ? c - '0' : -1;
}
static char parseDecimalDigit(char c)
{
	return ('0' <= c && c <= '9') ? c - '0' : -1;
}

static char parseBinaryDigit(char c)
{
	return ('0' == c || c == '1') ? c - '0' : -1;
}

static KMETHOD TokenFunc_ExtendedIntLiteral(KonohaContext *kctx, KonohaStack *sfp)
{
	kTokenVar *tk = (kTokenVar *)sfp[1].asObject;
	const char *source = S_text(sfp[2].asString);
	const char *start = source, *end;
	int c = *source++;
	/*
	 * DIGIT  = 0-9
	 * DIGITS = DIGIT | DIGIT DIGITS
	 * HEX    = 0-9a-fA-F
	 * HEXS   = HEX | HEX HEXS
	 * BIN    = 0 | 1
	 * BINS   = BIN | BIN BINS
	 * TAG    = "0x"  | "0b"
	 * HEXINT = ("0x" | "0X") HEXS
	 * INT    = DIGITS | HEXS | BINS
	 */
	int base = 10;
	bool isFloat = false;
	char (*parseDigit)(char) = parseDecimalDigit;
	if(c == '0') {
		c = *source++;
		switch (c) {
			case 'b':
				base = 2;  parseDigit = parseBinaryDigit; break;
			case 'x':
				base = 16; parseDigit = parseHexDigit; break;
			case '0':case '1':case '2':case '3':
			case '4':case '5':case '6':case '7':
				base = 8; parseDigit = parseOctalDigit;
				break;
			default:
				source--;
				break;
		}
	}
	for (; (c = *source) != 0; ++source) {
		if(c == '_') continue;
		if(parseDigit(c) == -1)
			break;
	}

	/*
	 * DIGIT  = 0-9
	 * DIGITS = DIGIT | DIGIT DIGITS
	 * INT    = DIGIT | DIGIT1-9 DIGITS
	 * FLOAT  = INT
	 *        | INT FRAC
	 *        | INT EXP
	 *        | INT FRAC EXP
	 * FRAC   = "." digits
	 * EXP    = E digits
	 * E      = 'e' | 'e+' | 'e-' | 'E' | 'E+' | 'E-'
	 */
	if(base != 10 && c != '.' && c != 'e' && c != 'E') {
		goto L_emit;
	}
	if(c == '.') {
		isFloat = true;
		source++;
		for (; (c = *source) != 0; ++source) {
			if(c == '_') continue;
			if(parseDecimalDigit(c) == -1)
				break;
		}
	}
	if(c == 'e' || c == 'E') {
		isFloat = true;
		c = *(++source);
		if(!('0' <= c && c <= '9') && !(c == '+' || c == '-')) {
			source--;
			goto L_emit;
		}
		if(c == '+' || c == '-') {
			c = *source++;
		}
		for (; (c = *source) != 0; ++source) {
			if(c == '_') continue;
			if(parseDecimalDigit(c) == -1)
				break;
		}
	}

	L_emit:;
	if(IS_NOTNULL(tk)) {
		/* skip unit */
		for (; (c = *source) != 0; ++source) {
			if(c == '_') continue;
			if(!isalpha(c))
				break;
		}
		end = source;
		KFieldSet(tk, tk->text, KLIB new_kString(kctx, OnField, start, end - start, StringPolicy_ASCII));
		tk->unresolvedTokenType = isFloat ? SYM_("$Float") : TokenType_INT;
	}
	KReturnUnboxValue(source - start);
}

static kint_t _kstrtoll(const char *p, char (*parseDigit)(char), int base)
{
	long long tmp = 0, prev = 0;
	char c;
	for (; (c = *p) != 0; ++p) {
		if(c == '_') continue;
		c = parseDigit(c);
		if(c == -1)
			break;
		tmp = tmp * base + c;
		if(tmp < prev) {
			/* Overflow!! */
			return 0;
		}
		prev = tmp;
	}
	return (kint_t) tmp;
}

static kint_t kstrtoll(const char *p)
{
	if(*p == '0') {
		if(*(p+1) == 'x' || *(p+1) == 'X') {
		return _kstrtoll(p+2, parseHexDigit, 16);
		}
		if(*(p+1) == 'b') {
			return _kstrtoll(p+2, parseBinaryDigit, 2);
		}
		if('0' <= *(p+1) && *(p+1) <= '7') {
			return _kstrtoll(p+1, parseOctalDigit, 8);
		}
	}
	return _kstrtoll(p, parseDecimalDigit, 10);
}

static KMETHOD TypeCheck_ExtendedIntLiteral(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_TypeCheck(stmt, expr, gma, reqty);
	kToken *tk = expr->termToken;
	long long n = kstrtoll(S_text(tk->text));
	KReturn(SUGAR kExpr_setUnboxConstValue(kctx, expr, TY_int, (uintptr_t)n));
}

static kbool_t int_defineSyntax(KonohaContext *kctx, kNameSpace *ns, KTraceInfo *trace)
{
	KDEFINE_SYNTAX SYNTAX[] = {
		{ KW_NumberPattern, 0,  NULL, 0, 0, NULL, NULL, NULL, NULL, TypeCheck_ExtendedIntLiteral, },
		{ SYM_("~"),  0, NULL, 0,                   Precedence_CStylePREUNARY, NULL, NULL, NULL, NULL, NULL, },
		{ SYM_("<<"), 0, NULL, Precedence_CStyleSHIFT,  0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_(">>"), 0, NULL, Precedence_CStyleSHIFT,  0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_("&"),  0, NULL, Precedence_CStyleBITAND, 0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_("|"),  0, NULL, Precedence_CStyleBITOR,  0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_("^"),  0, NULL, Precedence_CStyleBITXOR, 0,                     NULL, NULL, NULL, NULL, NULL, },
		{ KW_END, },
	};
	SUGAR kNameSpace_defineSyntax(kctx, ns, SYNTAX, trace);
	SUGAR kNameSpace_SetTokenFunc(kctx, ns, KW_NumberPattern, KonohaChar_Digit, new_SugarFunc(ns, TokenFunc_ExtendedIntLiteral));

	SugarSyntaxVar *syn = (SugarSyntaxVar *)SUGAR kNameSpace_GetSyntax(kctx, ns, SYM_("+"), 0);
	if(syn != NULL) {
		syn->precedence_op1  = Precedence_CStylePREUNARY;
	}
	return true;
}

/* ------------------------------------------------------------------------ */
/* assignment */

static KMETHOD Expression_BinarySugar(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Expression(stmt, tokenList, beginIdx, operatorIdx, endIdx);
	kToken *opToken = tokenList->TokenItems[operatorIdx];
	SugarSyntax *opSyntax = opToken->resolvedSyntaxInfo;
	if(opSyntax->macroParamSize == 2) {
		TokenSequence macro = {Stmt_nameSpace(stmt), tokenList};
		TokenSequence_push(kctx, macro);
		MacroSet macroParam[] = {
			{SYM_("X"), tokenList, beginIdx, operatorIdx},
			{SYM_("Y"), tokenList, operatorIdx+1, endIdx},
			{0, NULL, 0, 0},
		};
		macro.TargetPolicy.RemovingIndent = true;
		SUGAR TokenSequence_applyMacro(kctx, &macro, opSyntax->macroDataNULL_OnList, 0, kArray_size(opSyntax->macroDataNULL_OnList), opSyntax->macroParamSize, macroParam);
		kExpr *expr = SUGAR kStmt_parseExpr(kctx, stmt, macro.tokenList, macro.beginIdx, macro.endIdx, NULL);
		TokenSequence_pop(kctx, macro);
		KReturn(expr);
	}
}

static kbool_t cstyle_defineAssign(KonohaContext *kctx, kNameSpace *ns, KTraceInfo *trace)
{
	KDEFINE_SYNTAX SYNTAX[] = {
		{ SYM_("+="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_("-="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_("*="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_("/="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_("%="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },

		{ SYM_("<<"), 0, NULL, Precedence_CStyleSHIFT,  0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_(">>"), 0, NULL, Precedence_CStyleSHIFT,  0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_("&"),  0, NULL, Precedence_CStyleBITAND, 0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_("|"),  0, NULL, Precedence_CStyleBITOR,  0,                     NULL, NULL, NULL, NULL, NULL, },
		{ SYM_("^"),  0, NULL, Precedence_CStyleBITXOR, 0,                     NULL, NULL, NULL, NULL, NULL, },

		{ SYM_("|="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_("&="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_("<<="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_(">>="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ SYM_("^="), (SYNFLAG_ExprLeftJoinOp2), NULL, Precedence_CStyleASSIGN, 0, NULL, Expression_BinarySugar, NULL, NULL, NULL, },
		{ KW_END, },
	};
	SUGAR kNameSpace_defineSyntax(kctx, ns, SYNTAX, trace);
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("+="), 2,  "X Y X = (X) + (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("-="), 2,  "X Y X = (X) - (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("*="), 2,  "X Y X = (X) * (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("/="), 2,  "X Y X = (X) / (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("%="), 2,  "X Y X = (X) % (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("|="), 2,  "X Y X = (X) | (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("&="), 2,  "X Y X = (X) & (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("<<="), 2, "X Y X = (X) << (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_(">>="), 2, "X Y X = (X) >> (Y)");
	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("^="), 2,  "X Y X = (X) ^ (Y)");
	return true;
}

// --------------------------------------------------------------------------
/* null */

//## Boolean Object.isNull();
static KMETHOD Object_isNull(KonohaContext *kctx, KonohaStack *sfp)
{
	kObject *o = sfp[0].asObject;
	KReturnUnboxValue(IS_NULL(o));
}

//## Boolean Object.isNotNull();
static KMETHOD Object_isNotNull(KonohaContext *kctx, KonohaStack *sfp)
{
	kObject *o = sfp[0].asObject;
	KReturnUnboxValue(!IS_NULL(o));
}

static kbool_t null_defineMethod(KonohaContext *kctx, kNameSpace *ns, KTraceInfo *trace)
{
	KDEFINE_METHOD MethodData[] = {
		_Public|_Im|_Final|_Const, _F(Object_isNull),   TY_boolean, TY_Object, MN_("isNull"), 0,
		_Public|_Im|_Final|_Const, _F(Object_isNotNull), TY_boolean, TY_Object, MN_("isNotNull"), 0,
		DEND,
	};
	KLIB kNameSpace_LoadMethodData(kctx, ns, MethodData, trace);
	return true;
}

/* Syntax */

static KMETHOD TypeCheck_null(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_TypeCheck(stmt, expr, gma, reqty);
	if(reqty == TY_var) reqty = TY_Object;
	KReturn(SUGAR kExpr_setVariable(kctx, expr, gma, TEXPR_NULL, reqty, 0));
}

static KMETHOD Expression_isNull(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Expression(stmt, tokenList, beginIdx, operatorIdx, endIdx);
	if(operatorIdx + 2 == endIdx) {
		DBG_P("checking .. x == null");
		kTokenVar *tk = tokenList->TokenVarItems[operatorIdx+1];
		if(tk->resolvedSymbol == SYM_("null")) {
			kExpr *leftHandExpr = SUGAR kStmt_parseExpr(kctx, stmt, tokenList, beginIdx, operatorIdx, NULL);
			tk->resolvedSymbol = SYM_("isNull");
			KReturn(SUGAR new_UntypedCallStyleExpr(kctx, SYN_(Stmt_nameSpace(stmt), KW_ExprMethodCall), 2, tk, leftHandExpr));
		}
	}
	DBG_P("checking parent .. == ..");
}

static KMETHOD Expression_isNotNull(KonohaContext *kctx, KonohaStack *sfp)
{
	VAR_Expression(stmt, tokenList, beginIdx, operatorIdx, endIdx);
	if(operatorIdx + 2 == endIdx) {
		DBG_P("checking .. x != null");
		kTokenVar *tk = tokenList->TokenVarItems[operatorIdx+1];
		if(tk->resolvedSymbol == SYM_("null")) {
			kExpr *leftHandExpr = SUGAR kStmt_parseExpr(kctx, stmt, tokenList, beginIdx, operatorIdx, NULL);
			tk->resolvedSymbol = SYM_("isNotNull");
			KReturn(SUGAR new_UntypedCallStyleExpr(kctx, SYN_(Stmt_nameSpace(stmt), KW_ExprMethodCall), 2, tk, leftHandExpr));
		}
	}
	DBG_P("checking parent .. != ..");
}

static kbool_t null_defineSyntax(KonohaContext *kctx, kNameSpace *ns, KTraceInfo *trace)
{
	KDEFINE_SYNTAX SYNTAX[] = {
		{ SYM_("null"), 0, NULL, 0, 0, NULL, NULL, NULL, NULL, TypeCheck_null, },
		{ SYM_("NULL"), 0, NULL, 0, 0, NULL, NULL, NULL, NULL, TypeCheck_null, },
		{ KW_END, },
	};
	SUGAR kNameSpace_defineSyntax(kctx, ns, SYNTAX, trace);
	SUGAR kNameSpace_addSugarFunc(kctx, ns, SYM_("=="), SugarFunc_Expression, new_SugarFunc(ns, Expression_isNull));
	SUGAR kNameSpace_addSugarFunc(kctx, ns, SYM_("!="), SugarFunc_Expression, new_SugarFunc(ns, Expression_isNotNull));
	return true;
}

static kbool_t null_initPackage(KonohaContext *kctx, kNameSpace *ns, KTraceInfo *trace)
{
	null_defineMethod(kctx, ns, trace);
	null_defineSyntax(kctx, ns, trace);
	return true;
}


// --------------------------------------------------------------------------

static kbool_t cstyle_initPackage(KonohaContext *kctx, kNameSpace *ns, int argc, const char**args, KTraceInfo *trace)
{
	KDEFINE_SYNTAX defStatement[] = {
		{ SYM_("while"), 0, "\"while\" \"(\" $Expr \")\" $Block", 0, 0, NULL, NULL, NULL, Statement_while, NULL, },
		{ SYM_("do"), 0, "\"do\"  $Block \"while\" \"(\" $Expr \")\"", 0, 0, NULL, NULL, NULL, Statement_do, NULL, },
		{ SYM_("for"), 0, "\"for\" \"(\" $ForStmt \")\" $Block", 0, 0, NULL, NULL, NULL, Statement_CStyleFor, NULL, },
		{ SYM_("break"), 0, "\"break\"", 0, 0, NULL, NULL, NULL, Statement_break, NULL, },
		{ SYM_("continue"), 0, "\"continue\"", 0, 0, NULL, NULL, NULL, Statement_continue, NULL, },
		{ KW_END, }, /* sentinental */
	};
	SUGAR kNameSpace_defineSyntax(kctx, ns, defStatement, trace);

	KDEFINE_SYNTAX defLiteral[] = {
		{ SYM_("$SingleQuotedChar"), 0, NULL, 0, 0, NULL, NULL, NULL, NULL, TypeCheck_SingleQuotedChar, },
		{ KW_END, }, /* sentinental */
	};
	SUGAR kNameSpace_defineSyntax(kctx, ns, defLiteral, trace);
	SUGAR kNameSpace_SetTokenFunc(kctx, ns, SYM_("$SingleQuotedChar"), KonohaChar_Quote, new_SugarFunc(ns, TokenFunc_SingleQuotedChar));

	KDEFINE_SYNTAX defExpression[] = {
		{ SYM_("[]"), SYNFLAG_ExprPostfixOp2, NULL, Precedence_CStyleCALL, 0, NULL, Expression_Indexer, NULL, NULL, NULL, },
//		{ SYM_("++"), SYNFLAG_ExprPostfixOp2, NULL, Precedence_CStyleCALL, Precedence_CStylePREUNARY, NULL, Expression_Increment,},
//		{ SYM_("--"), SYNFLAG_ExprPostfixOp2, NULL, Precedence_CStyleCALL, Precedence_CStylePREUNARY, NULL, Expression_Increment,},
		{ KW_END, }, /* sentinental */
	};
	SUGAR kNameSpace_defineSyntax(kctx, ns, defExpression, trace);
//	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("++"), 1,  "X X = (X) + 1 X ${int _ = X; X = (X) + 1; _}");
//	SUGAR kNameSpace_SetMacroData(kctx, ns, SYM_("--"), 1,  "X X = (X) - 1 X ${int _ = X; X = (X) - 1; _}");

	int_defineMethod(kctx, ns, trace);
	int_defineSyntax(kctx, ns, trace);
	cstyle_defineAssign(kctx, ns, trace);

	null_initPackage(kctx, ns, trace);
	return true;
}

static kbool_t cstyle_setupPackage(KonohaContext *kctx, kNameSpace *ns, isFirstTime_t isFirstTime, KTraceInfo *trace)
{
	return true;
}

// --------------------------------------------------------------------------

KDEFINE_PACKAGE* cstyle_init(void)
{
	static KDEFINE_PACKAGE d = {0};
	KSetPackageName(d, "cstyle", "1.0");
	d.initPackage    = cstyle_initPackage;
	d.setupPackage   = cstyle_setupPackage;
	return &d;
}

// --------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif
