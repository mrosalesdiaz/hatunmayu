#!/bin/bash
export XCODE_HOME="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

export PATH=/usr/local/bin:$PATH
cd $XCODE_HOME && find ../game/Classes  -name "*.h" -o  -name "*.cpp" | sed 's| |\\ |g' | xargs clang-format -style=file  -i
