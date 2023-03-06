/*
 * Copyright (C) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "framework/argument/basic_argument.h"
#include "framework/test_case/test_case.h"

struct MultipleImmediateCmdListsWithDependenciesArguments : TestCaseArgumentContainer {
    PositiveIntegerArgument cmdlistCount;
    MultipleImmediateCmdListsWithDependenciesArguments()
        : cmdlistCount(*this, "cmdlistCount", "Count of command lists") {}
};

struct MultipleImmediateCmdListsWithDependencies : TestCase<MultipleImmediateCmdListsWithDependenciesArguments> {
    using TestCase<MultipleImmediateCmdListsWithDependenciesArguments>::TestCase;

    std::string getTestCaseName() const override {
        return "MultipleImmediateCmdListsWithDependencies";
    }

    std::string getHelp() const override {
        return "Creates N immediate command lists. Submits kernels in order to each of those"
               "Each kernel has a dependency on previous one"
               "Submissions are small to allows concurrent execution"
               "Meassures time from scheduling start, till all command lists are completed";
    }
};