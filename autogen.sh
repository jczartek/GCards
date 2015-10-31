#!/bin/sh

srcdir=$(dirname $0)
test -z "$srcdir" && srcdir=.

(test -f $srcdir/src/gc-main.c) || {
  echo -n "**Error**: Directory "\`$srcdir\`" does not look the "
  echo "top-level GCards directory."
  exit 1
}

which gnome-autogen.sh || {
  echo "You need to install gnome-common!"
  exit 1
}

. gnome-autogen.sh
