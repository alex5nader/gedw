#!/usr/bin/env nix-shell
#!nix-shell -p coreutils dash -i dash

find "$2" -type f -name "*.$1"
