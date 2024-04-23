#pragma once

#include "fehler_abfangen.h"
#include "header.h"

#ifndef service_h
#define service_h

// funktionsdeklarationen
void zahl_eingabe(float*, float*, int*, int*, int*);
int is_int_float(char[GROESSE]);
void ausgeben(int, int, int, float);

#endif