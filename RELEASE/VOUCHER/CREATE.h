#pragma once
// #include <unistd.h>
// #include <fcntl.h>
#include <random>
#include <iostream>
#include <fstream>

#include "MANAGE.h"
#include "../DATETIME/DATE.h"
#include "../ITEM/ITEMMANAGE.h"

void getDATE(DATE &);
void getVoucherInfo(size_t &, size_t &, size_t &, size_t &, DATE &);
void createVoucher();

#include "CREATE.cc"