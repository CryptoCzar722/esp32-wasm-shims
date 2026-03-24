#include "Arduino.h"
#include <emscripten.h>

// User sketch provides setup() and loop()
extern "C" void setup(void);
extern "C" void loop(void);

extern "C" int js_should_stop(void);

int main() {
  setup();
  while (!js_should_stop()) {
    loop();
    emscripten_sleep(1); // Yield to browser event loop
  }
  return 0;
}
