/*
    TickTock is an open-source Time Series Database for your metrics.
    Copyright (C) 2020-2021  Yongtao You (yongtao.you@gmail.com),
    Yi Lin (ylin30@gmail.com), and Yalei Wang (wang_yalei@yahoo.com).

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <cstring>
#include <algorithm>
#include "utils.h"
#include "max_subset_test.h"

#define INDEX(x, y, dim)    ((x) + ((y) * (dim)))
//#define INDEX(x, y, dim)    ((y) + ((x) * (dim)))


using namespace tt;

namespace tt_test
{


void
MaxSubsetTests::run()
{
    log("Running %s...", m_name);

    test1();

    log("Finished %s", m_name);
}

void
MaxSubsetTests::test1()
{
    std::vector<int> subset;
    int16_t set[16];
    int i;

    i = 0;
    set[i++] = 2049; set[i++] = 2048;
    max_subset_4k(set, i, subset);
    confirm(subset.size() == 1);
    confirm(subset[0] == 0);

    i = 0;
    set[i++] = 2048; set[i++] = 2049;
    max_subset_4k(set, i, subset);
    confirm(subset.size() == 1);
    confirm(subset[0] == 1);

    i = 0;
    set[i++] = 1; set[i++] = 2048; set[i++] = 2048;
    max_subset_4k(set, i, subset);
    confirm(subset.size() == 2);
    confirm(subset[0] == 1);
    confirm(subset[1] == 2);

    i = 0;
    set[i++] = 1; set[i++] = 2048; set[i++] = 2; set[i++] = 2048;
    max_subset_4k(set, i, subset);
    confirm(subset.size() == 2);
    confirm(subset[0] == 1);
    confirm(subset[1] == 3);

    i = 0;
    set[i++] = 10; set[i++] = 20; set[i++] = 450; set[i++] = 4095;
    max_subset_4k(set, i, subset);
    confirm(subset.size() == 1);
    confirm(subset[0] == 3);

    i = 0;
    set[i++] = 1024; set[i++] = 20; set[i++] = 1024; set[i++] = 4095; set[i++] = 2048;
    max_subset_4k(set, i, subset);
    confirm(subset.size() == 3);
    confirm(subset[0] == 0);
    confirm(subset[1] == 2);
    confirm(subset[2] == 4);

    i = 0;
    set[i++] = 12; set[i++] = 1000; set[i++] = 4; set[i++] = 3000;
    max_subset_4k(set, i, subset);
    confirm(subset.size() == 4);
    confirm(subset[0] == 0);
    confirm(subset[1] == 1);
    confirm(subset[2] == 2);
    confirm(subset[3] == 3);

    m_stats.add_passed(1);
}


}
