#ifndef MATH_H
#define MATH_H

#define NITEMS(arr) (sizeof(arr) / (sizeof(arr)[0]))

typedef struct vec3{
  float x,y,z;
} vec3;

typedef struct mat4 {
  float m[16];
} mat4;

float lerp(float a, float b, float f)
{
  return a * (1.0 - f) + (b * f);
}

#endif
