//===--- AllDiagnostics.h - Aggregate Diagnostic headers --------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief Includes all the separate Diagnostic headers & some related helpers.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_BASIC_ALLDIAGNOSTICS_H
#define LLVM_CLANG_BASIC_ALLDIAGNOSTICS_H

#include "clang/Lex/LexDiagnostic.h"

namespace clang {
template <size_t SizeOfStr, typename FieldType>
class StringSizerHelper {
  char FIELD_TOO_SMALL[SizeOfStr <= FieldType(~0U) ? 1 : -1];
public:
  enum { Size = SizeOfStr };
};
} // end namespace clang 

#define STR_SIZE(str, fieldTy) clang::StringSizerHelper<sizeof(str)-1, \
                                                        fieldTy>::Size 

#endif
