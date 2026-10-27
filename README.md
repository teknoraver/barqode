# BarQode

BarQode generates QR codes and DataMatrix codes from a text, while typing.
The module size can be changed with the zoom slider, and the code can be saved as a PNG image.

## Build

Requirements: CMake 3.19 or newer, Qt 6 (Widgets), [libqrencode](https://fukuchi.org/works/qrencode/)
and [libdmtx](https://github.com/dmtx/libdmtx).

- Debian/Ubuntu: `apt install cmake qt6-base-dev libqrencode-dev libdmtx-dev`
- Fedora: `dnf install cmake qt6-qtbase-devel qrencode-devel libdmtx-devel`

```
cmake -B build
cmake --build build
```

## License

Copyright (C) 2009 Matteo Croce

BarQode is released under the GNU General Public License version 3 or later, see [COPYING](COPYING).
