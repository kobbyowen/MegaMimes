# MegaMimes v2.1

Tiny, dependency-free C99 library for MIME detection and content classification.

MegaMimes probes files with layered evidence:

- magic signatures
- container hints
- extension fallback (disabled in strict mode)

It also reports text/binary classification and text encoding.

## What's New in 2.1

- confidence scoring for each detection candidate
- strict mode for security-oriented detection
- ranked candidate output (best + alternatives)
- suspicious flag for conflicting/weak evidence
- runtime tuning APIs:
  - mega_set_mode
  - mega_set_max_bytes

## Core Features

- MIME detection from multiple signal sources
- confidence-based result selection
- candidate list in MegaFileInfo
- strict mode requiring strong signals
- UTF BOM + UTF-8 based text/encoding detection
- zero external dependencies
- portable C99 (Linux/macOS/Windows)

## Build (shared lib + CLI)

```bash
rm -rf build
cmake -S . -B build -DMEGA_BUILD_SHARED=ON -DMEGA_BUILD_CLI=ON -DMEGA_ENABLE_TESTS=ON
cmake --build build -j
```

## Run Tests

```bash
ctest --test-dir build --output-on-failure -V
```

## Install (optional)

```bash
cmake --install build --prefix /usr/local
pkg-config --cflags --libs megamimes
```

## CLI Usage

```bash
# Analyze a file
./build/mmime /path/to/file

# JSON output
./build/mmime /path/to/file --json
```

## Minimal C API Usage

```c
#include "megamimes.h"
#include <stdio.h>

int main(void) {
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) return 1;

  mega_set_mode(ctx, MEGA_MODE_STRICT);
  mega_set_max_bytes(ctx, 4096);

  MegaFileInfo* info = NULL;
  if (mega_probe_path(ctx, "file.pdf", &info) == MEGA_OK) {
    printf("mime=%s source=%s confidence=%.2f suspicious=%d\n",
      info->mime_type,
      info->source,
      info->confidence,
      info->suspicious);

    for (size_t i = 0; i < info->candidate_count; i++) {
      printf("candidate[%zu] %s (%.2f)\n",
        i,
        info->candidates[i].mime,
        info->candidates[i].confidence);
    }
  }

  mega_free(ctx, info);
  mega_close(ctx);
  return 0;
}
```

## CMake Options

- MEGA_BUILD_SHARED (ON): build shared library
- MEGA_BUILD_STATIC (OFF): also build static library
- MEGA_BUILD_CLI (ON): build mmime tool
- MEGA_ENABLE_TESTS (ON): enable tests via CTest
- MEGA_ENABLE_SIMD (OFF): enable optional SIMD fast paths

## Project Layout

```text
.
|- include/   # public headers
|- src/       # library sources
|- tools/     # mmime CLI
|- tests/     # CTest suites
`- CMakeLists.txt
```
