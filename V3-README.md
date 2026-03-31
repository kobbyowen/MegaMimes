Here’s a **clean, production-ready README draft for MegaMimes v3**, reflecting exactly the features you selected and positioning it as a more serious system library 👇

---

# MegaMimes v3

High-performance, dependency-free C library for **MIME detection and content intelligence**.

MegaMimes v3 builds on v2 with **confidence scoring, stricter validation modes, extensibility, and improved tooling**, making it suitable for **security-sensitive and high-throughput systems**.

---

## ✨ What’s New in v3

- 📊 **Confidence scoring** for all detections
- 🔒 **Safe mode (strict detection)** to avoid weak guesses
- 🧱 **Size limits** to prevent abuse and excessive reads
- 🧩 **Custom MIME registry** for user-defined formats
- 🧰 Enhanced **CLI with batch + debug modes**
- 📦 Richer **output structure (multiple candidates)**
- 🧪 Expanded **testing (corpus + fuzz-ready)**

---

## 🚀 Features

### 🔍 Multi-layer MIME Detection

- Magic signature matching (primary)
- Container hints (e.g., ZIP-based formats)
- Extension fallback (optional / disable in strict mode)

---

### 📊 Confidence Scoring

Every result includes a confidence score:

| Source    | Confidence    |
| --------- | ------------- |
| Magic     | High (~0.9+)  |
| Container | Medium (~0.7) |
| Extension | Low (~0.4)    |

```c
info->confidence; // float (0.0 → 1.0)
```

---

### 🔒 Safe Mode (Strict Detection)

Disable weak signals and enforce strong matches:

```c
mega_set_mode(ctx, MEGA_MODE_STRICT);
```

**Behavior:**

- ❌ disables extension fallback
- ✅ requires magic or strong container match
- ✅ reduces false positives

---

### 🧱 Size Limits (Abuse Protection)

Limit how many bytes are read during detection:

```c
mega_set_max_bytes(ctx, 4096);
```

Prevents:

- large file overhead
- malicious payload scanning abuse

---

### 🧩 Custom MIME Registry

Extend detection with your own rules:

```c
mega_register_mime(ctx, &(MegaMimeRule){
  .mime = "application/x-custom",
  .extension = "cust",
  .magic = (uint8_t*)"\xDE\xAD\xBE\xEF",
  .magic_len = 4
});
```

Perfect for:

- proprietary formats
- internal tooling
- domain-specific pipelines

---

### 📦 Rich Output Structure

```c
typedef struct {
  const char* mime_type;
  const char* source;

  float confidence;

  int is_text;
  const char* text_encoding;

  MegaMimeCandidate* candidates;
  size_t candidate_count;

  int suspicious;
} MegaFileInfo;
```

Supports:

- top candidate + alternatives
- confidence-based ranking
- suspicious file detection

---

### ⚠️ Suspicious File Detection

Flags potentially unsafe or inconsistent files:

- extension mismatch
- weak/ambiguous signals
- malformed headers

```c
info->suspicious; // 0 or 1
```

---

## 🧰 CLI Usage (`mmime`)

### Basic

```bash
mmime file.pdf
```

---

### JSON Output

```bash
mmime file.pdf --json
```

---

### Top Candidates

```bash
mmime file.bin --top 3
```

---

### Explain Mode (Debug)

```bash
mmime file.bin --explain
```

Example:

```
Matched: %PDF → application/pdf (confidence: 0.98)
```

---

### Strict Mode

```bash
mmime file.bin --strict
```

---

### Batch Mode

```bash
mmime *.pdf --json
```

---

## 🧪 Testing

### Run tests

```bash
ctest --test-dir build --output-on-failure -V
```

---

### Test Strategy

- ✅ Unit tests (magic, encoding, fallback)
- ✅ Corpus tests (real-world files)
- ✅ Edge cases (truncated / malformed files)
- 🚧 Fuzz testing ready (libFuzzer / AFL)

---

## 🏗 Build

```bash
rm -rf build
cmake -S . -B build \
  -DMEGA_BUILD_SHARED=ON \
  -DMEGA_BUILD_CLI=ON \
  -DMEGA_ENABLE_TESTS=ON

cmake --build build -j
```

---

## 📦 Install

```bash
cmake --install build --prefix /usr/local
pkg-config --cflags --libs megamimes
```

---

## 🧠 Minimal C API

```c
#include "megamimes.h"

int main(void) {
  MegaMimesCtx* ctx = mega_open(NULL);
  if (!ctx) return 1;

  mega_set_mode(ctx, MEGA_MODE_STRICT);
  mega_set_max_bytes(ctx, 4096);

  MegaFileInfo* info = NULL;

  if (mega_probe_path(ctx, "file.pdf", &info) == MEGA_OK) {
    // info->mime_type
    // info->confidence
    // info->candidates
    // info->suspicious
  }

  mega_free(ctx, info);
  mega_close(ctx);
  return 0;
}
```

---

## ⚙️ CMake Options

- `MEGA_BUILD_SHARED` (ON) – build shared library
- `MEGA_BUILD_STATIC` (OFF) – build static library
- `MEGA_BUILD_CLI` (ON) – build `mmime`
- `MEGA_ENABLE_TESTS` (ON) – enable tests
- `MEGA_ENABLE_SIMD` (OFF) – optional SIMD optimizations

---

## 📁 Project Layout

```
.
├─ include/          # public headers
├─ src/              # core implementation
├─ tools/            # mmime CLI
├─ tests/            # test suites (unit + corpus)
└─ CMakeLists.txt
```

---

## 🎯 Design Goals

- ⚡ Fast and predictable
- 🔒 Safe by default (strict mode available)
- 🧩 Extensible (custom MIME registry)
- 🧪 Testable and fuzzable
- 📦 Zero dependencies

---

## 📌 Positioning

MegaMimes v3 is not just a MIME detector:

> It is a **lightweight content intelligence engine for systems programming**

---

If you want next, I can:

- draft the **actual `megamimes.h` v3 API**
- or write **AI prompts to implement each feature step-by-step (like your query engine flow)**
