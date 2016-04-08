#include "clang/Basic/Attributes.h"
#include "clang/Basic/IdentifierTable.h"
#include "llvm/ADT/StringSwitch.h"
using namespace clang;

int clang::hasAttribute(AttrSyntax Syntax, const IdentifierInfo *Scope,
                        const IdentifierInfo *Attr, const TargetInfo &Target,
                        const LangOptions &LangOpts) {

  return 0;
}
