# MegaMimes v2.1

Tiny, dependency-free C library to:

- Detect **MIME types** (magic signatures → container hints → extension fallback)
- Tell if a file is **text or binary**
- Guess **text encoding** (BOM + UTF-8 validation)

Includes a lightweight CLI: `mmime` and a CTest suite in `tests/`.

## Features

- 🧪 Magic signatures for common formats (PDF/PNG/JPEG/GIF/WebP/ZIP/MP4/MP3/ELF/PE, soft JSON)
- 🔤 Text vs. binary check with UTF-8 validator and BOM detection (UTF-8/UTF-16/UTF-32 LE/BE)
- 🧩 Extension fallback with a tiny, customizable table (includes **Roff manpages** `1`–`8`)
- 🧰 Zero external deps, C99, portable (Linux/macOS/Windows)
- 🧪 CTest suite in `tests/`

## Build (shared lib + CLI)

```bash
rm -rf build
cmake -S . -B build -DMEGA_BUILD_SHARED=ON -DMEGA_BUILD_CLI=ON -DMEGA_ENABLE_TESTS=ON
cmake --build build -j
```

## Run tests

```bash
ctest --test-dir build --output-on-failure -V
```

## Install (optional)

```bash
cmake --install build --prefix /usr/local
# pkg-config
pkg-config --cflags --libs megamimes
```

## CLI usage

```bash
# analyze a file
./build/mmime /path/to/file

# JSON output
./build/mmime /path/to/file --json
```

## Minimal C API usage

```c
#include "megamimes.h"

int main(void) {
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) return 1;
  MegaFileInfo* info = NULL;
  if (mega_probe_path(ctx, "file.pdf", &info) == MEGA_OK) {
    /* info->mime_type, info->source ("magic|container|extension"),
       info->is_text, info->text_encoding */
  }
  mega_free(ctx, info);
  mega_close(ctx);
  return 0;
}
```

## CMake Options

- `MEGA_BUILD_SHARED` (ON) – build shared library
- `MEGA_BUILD_STATIC` (OFF) – also build static library
- `MEGA_BUILD_CLI` (ON) – build `mmime` tool
- `MEGA_ENABLE_TESTS` (ON) – enable `tests/` via CTest
- `MEGA_ENABLE_SIMD` (OFF) – enable optional SIMD fast-paths

## Project layout

```
.
├─ include/          # public headers (megamimes.h)
├─ src/              # library sources
├─ tools/            # mmime CLI
├─ tests/            # CTest suites
└─ CMakeLists.txt
```
