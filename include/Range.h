/*
 * Copyright (C) 2018 Miloš Stojanović
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#ifndef RANGE_H
#define RANGE_H

#include <stdexcept>

template <typename T>
class Range {
	T min;
	T max;
public:
	Range() = default;
	Range(T Min, T Max) : min{Min}, max{Max} {
		if (Min > Max) {
			throw std::range_error("Min is greater than max.");
		}
	}

	T GetMin() { return min; }
	T GetMax() { return max; }
};

#endif