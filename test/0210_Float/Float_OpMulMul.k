// generated by kimio kurmaitsu

import("Type.Float");

float fabs(float v) {
    if(v < 0.0) return -v;
    return v;
}



void test() {
  int a = 1;
  float fa = 3.14159;
  assert(0.5 * 0.5 * 0.5 - (0.125000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * 0.5 * a - (0.250000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * 0.5 * fa - (0.785397500000000) <= FLOAT_EPSILON*10);
  assert(0.5 * 0.5 * fabs(-3.0) - (0.750000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * 0.5 * 3.14159 - (0.785397500000000) <= FLOAT_EPSILON*10);
  assert(0.5 * 0.5 * -fa - (-0.785397500000000) <= FLOAT_EPSILON*10);
  assert(0.5 * a * 0.5 - (0.250000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * a * a - (0.500000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * a * fa - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * a * fabs(-3.0) - (1.500000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * a * 3.14159 - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * a * -fa - (-1.570795000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * fa * 0.5 - (0.785397500000000) <= FLOAT_EPSILON*10);
  assert(0.5 * fa * a - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * fa * fa - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * fa * fabs(-3.0) - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(0.5 * fa * 3.14159 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * fa * -fa - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * fabs(-3.0) * 0.5 - (0.750000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * fabs(-3.0) * a - (1.500000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * fabs(-3.0) * fa - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(0.5 * fabs(-3.0) * fabs(-3.0) - (4.500000000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * fabs(-3.0) * 3.14159 - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(0.5 * fabs(-3.0) * -fa - (-4.712384999999999) <= FLOAT_EPSILON*10);
  assert(0.5 * 3.14159 * 0.5 - (0.785397500000000) <= FLOAT_EPSILON*10);
  assert(0.5 * 3.14159 * a - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * 3.14159 * fa - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * 3.14159 * fabs(-3.0) - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(0.5 * 3.14159 * 3.14159 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * 3.14159 * -fa - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * -fa * 0.5 - (-0.785397500000000) <= FLOAT_EPSILON*10);
  assert(0.5 * -fa * a - (-1.570795000000000) <= FLOAT_EPSILON*10);
  assert(0.5 * -fa * fa - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * -fa * fabs(-3.0) - (-4.712384999999999) <= FLOAT_EPSILON*10);
  assert(0.5 * -fa * 3.14159 - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(0.5 * -fa * -fa - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(a * 0.5 * 0.5 - (0.250000000000000) <= FLOAT_EPSILON*10);
  assert(a * 0.5 * a - (0.500000000000000) <= FLOAT_EPSILON*10);
  assert(a * 0.5 * fa - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(a * 0.5 * fabs(-3.0) - (1.500000000000000) <= FLOAT_EPSILON*10);
  assert(a * 0.5 * 3.14159 - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(a * 0.5 * -fa - (-1.570795000000000) <= FLOAT_EPSILON*10);
  assert(a * a * 0.5 - (0.500000000000000) <= FLOAT_EPSILON*10);
  assert(a * a * a - (1.000000000000000) <= FLOAT_EPSILON*10);
  assert(a * a * fa - (3.141590000000000) <= FLOAT_EPSILON*10);
  assert(a * a * fabs(-3.0) - (3.000000000000000) <= FLOAT_EPSILON*10);
  assert(a * a * 3.14159 - (3.141590000000000) <= FLOAT_EPSILON*10);
  assert(a * a * -fa - (-3.141590000000000) <= FLOAT_EPSILON*10);
  assert(a * fa * 0.5 - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(a * fa * a - (3.141590000000000) <= FLOAT_EPSILON*10);
  assert(a * fa * fa - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * fa * fabs(-3.0) - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(a * fa * 3.14159 - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * fa * -fa - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * fabs(-3.0) * 0.5 - (1.500000000000000) <= FLOAT_EPSILON*10);
  assert(a * fabs(-3.0) * a - (3.000000000000000) <= FLOAT_EPSILON*10);
  assert(a * fabs(-3.0) * fa - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(a * fabs(-3.0) * fabs(-3.0) - (9.000000000000000) <= FLOAT_EPSILON*10);
  assert(a * fabs(-3.0) * 3.14159 - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(a * fabs(-3.0) * -fa - (-9.424769999999999) <= FLOAT_EPSILON*10);
  assert(a * 3.14159 * 0.5 - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(a * 3.14159 * a - (3.141590000000000) <= FLOAT_EPSILON*10);
  assert(a * 3.14159 * fa - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * 3.14159 * fabs(-3.0) - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(a * 3.14159 * 3.14159 - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * 3.14159 * -fa - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * -fa * 0.5 - (-1.570795000000000) <= FLOAT_EPSILON*10);
  assert(a * -fa * a - (-3.141590000000000) <= FLOAT_EPSILON*10);
  assert(a * -fa * fa - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * -fa * fabs(-3.0) - (-9.424769999999999) <= FLOAT_EPSILON*10);
  assert(a * -fa * 3.14159 - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(a * -fa * -fa - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(fa * 0.5 * 0.5 - (0.785397500000000) <= FLOAT_EPSILON*10);
  assert(fa * 0.5 * a - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(fa * 0.5 * fa - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(fa * 0.5 * fabs(-3.0) - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fa * 0.5 * 3.14159 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(fa * 0.5 * -fa - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(fa * a * 0.5 - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(fa * a * a - (3.141590000000000) <= FLOAT_EPSILON*10);
  assert(fa * a * fa - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(fa * a * fabs(-3.0) - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fa * a * 3.14159 - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(fa * a * -fa - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(fa * fa * 0.5 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(fa * fa * a - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(fa * fa * fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * fa * fabs(-3.0) - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fa * fa * 3.14159 - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * fa * -fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * fabs(-3.0) * 0.5 - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fa * fabs(-3.0) * a - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fa * fabs(-3.0) * fa - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fa * fabs(-3.0) * fabs(-3.0) - (28.274309999999996) <= FLOAT_EPSILON*10);
  assert(fa * fabs(-3.0) * 3.14159 - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fa * fabs(-3.0) * -fa - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fa * 3.14159 * 0.5 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(fa * 3.14159 * a - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(fa * 3.14159 * fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * 3.14159 * fabs(-3.0) - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fa * 3.14159 * 3.14159 - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * 3.14159 * -fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * -fa * 0.5 - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(fa * -fa * a - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(fa * -fa * fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * -fa * fabs(-3.0) - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fa * -fa * 3.14159 - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fa * -fa * -fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 0.5 * 0.5 - (0.750000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 0.5 * a - (1.500000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 0.5 * fa - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 0.5 * fabs(-3.0) - (4.500000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 0.5 * 3.14159 - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 0.5 * -fa - (-4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * a * 0.5 - (1.500000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * a * a - (3.000000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * a * fa - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * a * fabs(-3.0) - (9.000000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * a * 3.14159 - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * a * -fa - (-9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fa * 0.5 - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fa * a - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fa * fa - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fa * fabs(-3.0) - (28.274309999999996) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fa * 3.14159 - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fa * -fa - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fabs(-3.0) * 0.5 - (4.500000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fabs(-3.0) * a - (9.000000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fabs(-3.0) * fa - (28.274310000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fabs(-3.0) * fabs(-3.0) - (27.000000000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fabs(-3.0) * 3.14159 - (28.274310000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * fabs(-3.0) * -fa - (-28.274310000000000) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 3.14159 * 0.5 - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 3.14159 * a - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 3.14159 * fa - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 3.14159 * fabs(-3.0) - (28.274309999999996) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 3.14159 * 3.14159 - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * 3.14159 * -fa - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * -fa * 0.5 - (-4.712384999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * -fa * a - (-9.424769999999999) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * -fa * fa - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * -fa * fabs(-3.0) - (-28.274309999999996) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * -fa * 3.14159 - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(fabs(-3.0) * -fa * -fa - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(3.14159 * 0.5 * 0.5 - (0.785397500000000) <= FLOAT_EPSILON*10);
  assert(3.14159 * 0.5 * a - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(3.14159 * 0.5 * fa - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(3.14159 * 0.5 * fabs(-3.0) - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(3.14159 * 0.5 * 3.14159 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(3.14159 * 0.5 * -fa - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(3.14159 * a * 0.5 - (1.570795000000000) <= FLOAT_EPSILON*10);
  assert(3.14159 * a * a - (3.141590000000000) <= FLOAT_EPSILON*10);
  assert(3.14159 * a * fa - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(3.14159 * a * fabs(-3.0) - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(3.14159 * a * 3.14159 - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(3.14159 * a * -fa - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(3.14159 * fa * 0.5 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(3.14159 * fa * a - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(3.14159 * fa * fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * fa * fabs(-3.0) - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(3.14159 * fa * 3.14159 - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * fa * -fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * fabs(-3.0) * 0.5 - (4.712384999999999) <= FLOAT_EPSILON*10);
  assert(3.14159 * fabs(-3.0) * a - (9.424769999999999) <= FLOAT_EPSILON*10);
  assert(3.14159 * fabs(-3.0) * fa - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(3.14159 * fabs(-3.0) * fabs(-3.0) - (28.274309999999996) <= FLOAT_EPSILON*10);
  assert(3.14159 * fabs(-3.0) * 3.14159 - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(3.14159 * fabs(-3.0) * -fa - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(3.14159 * 3.14159 * 0.5 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(3.14159 * 3.14159 * a - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(3.14159 * 3.14159 * fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * 3.14159 * fabs(-3.0) - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(3.14159 * 3.14159 * 3.14159 - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * 3.14159 * -fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * -fa * 0.5 - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(3.14159 * -fa * a - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(3.14159 * -fa * fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * -fa * fabs(-3.0) - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(3.14159 * -fa * 3.14159 - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(3.14159 * -fa * -fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * 0.5 * 0.5 - (-0.785397500000000) <= FLOAT_EPSILON*10);
  assert(-fa * 0.5 * a - (-1.570795000000000) <= FLOAT_EPSILON*10);
  assert(-fa * 0.5 * fa - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(-fa * 0.5 * fabs(-3.0) - (-4.712384999999999) <= FLOAT_EPSILON*10);
  assert(-fa * 0.5 * 3.14159 - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(-fa * 0.5 * -fa - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(-fa * a * 0.5 - (-1.570795000000000) <= FLOAT_EPSILON*10);
  assert(-fa * a * a - (-3.141590000000000) <= FLOAT_EPSILON*10);
  assert(-fa * a * fa - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(-fa * a * fabs(-3.0) - (-9.424769999999999) <= FLOAT_EPSILON*10);
  assert(-fa * a * 3.14159 - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(-fa * a * -fa - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(-fa * fa * 0.5 - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(-fa * fa * a - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(-fa * fa * fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * fa * fabs(-3.0) - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(-fa * fa * 3.14159 - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * fa * -fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * fabs(-3.0) * 0.5 - (-4.712384999999999) <= FLOAT_EPSILON*10);
  assert(-fa * fabs(-3.0) * a - (-9.424769999999999) <= FLOAT_EPSILON*10);
  assert(-fa * fabs(-3.0) * fa - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(-fa * fabs(-3.0) * fabs(-3.0) - (-28.274309999999996) <= FLOAT_EPSILON*10);
  assert(-fa * fabs(-3.0) * 3.14159 - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(-fa * fabs(-3.0) * -fa - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(-fa * 3.14159 * 0.5 - (-4.934793864050000) <= FLOAT_EPSILON*10);
  assert(-fa * 3.14159 * a - (-9.869587728099999) <= FLOAT_EPSILON*10);
  assert(-fa * 3.14159 * fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * 3.14159 * fabs(-3.0) - (-29.608763184299995) <= FLOAT_EPSILON*10);
  assert(-fa * 3.14159 * 3.14159 - (-31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * 3.14159 * -fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * -fa * 0.5 - (4.934793864050000) <= FLOAT_EPSILON*10);
  assert(-fa * -fa * a - (9.869587728099999) <= FLOAT_EPSILON*10);
  assert(-fa * -fa * fa - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * -fa * fabs(-3.0) - (29.608763184299995) <= FLOAT_EPSILON*10);
  assert(-fa * -fa * 3.14159 - (31.006198110721677) <= FLOAT_EPSILON*10);
  assert(-fa * -fa * -fa - (-31.006198110721677) <= FLOAT_EPSILON*10);
}

test();
