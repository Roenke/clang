//===--- Warnings.cpp - C-Language Front-end ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Command line warning options handler.
//
//===----------------------------------------------------------------------===//
//
// This file is responsible for handling all warning options. This includes
// a number of -Wfoo options and their variants, which are driven by TableGen-
// generated data, and the special cases -pedantic, -pedantic-errors, -w,
// -Werror and -Wfatal-errors.
//
// Each warning option controls any number of actual warnings.
// Given a warning option 'foo', the following are valid:
//    -Wfoo, -Wno-foo, -Werror=foo, -Wfatal-errors=foo
//
// Remark options are also handled here, analogously, except that they are much
// simpler because a remark can't be promoted to an error.
#include "clang/Basic/AllDiagnostics.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticOptions.h"
#include <algorithm>
#include <cstring>
#include <utility>
using namespace clang;

void clang::ProcessWarningOptions(DiagnosticsEngine &Diags,
                                  const DiagnosticOptions &Opts,
                                  bool ReportDiags) {
}
