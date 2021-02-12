#!/bin/bash

export XCODE_HOME="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd $XCODE_HOME && cd ../game/mac-build/ && cmake .. -GXcode

unset XCODE_HOME
