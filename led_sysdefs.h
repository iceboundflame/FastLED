#ifndef __INC_LED_SYSDEFS_H
#define __INC_LED_SYSDEFS_H

#include "FastLED.h"

#include "fastled_config.h"

#if defined(NRF51) || defined(__RFduino__) || defined (__Simblee__)
#include "platforms/arm/nrf51/led_sysdefs_arm_nrf51.h"
#elif defined(__MK20DX128__) || defined(__MK20DX256__)
// Include k20/T3 headers
#include "platforms/arm/k20/led_sysdefs_arm_k20.h"
#elif defined(__MK66FX1M0__) || defined(__MK64FX512__)
// Include k66/T3.6 headers
#include "platforms/arm/k66/led_sysdefs_arm_k66.h"
#elif defined(__MKL26Z64__)
// Include kl26/T-LC headers
#include "platforms/arm/kl26/led_sysdefs_arm_kl26.h"
#elif defined(__SAM3X8E__)
// Include sam/due headers
#include "platforms/arm/sam/led_sysdefs_arm_sam.h"
#elif defined(STM32F10X_MD) || defined(__STM32F1__)
#include "platforms/arm/stm32/led_sysdefs_arm_stm32.h"
#elif defined(__SAMD21G18A__) || defined(__SAMD21J18A__) || defined(__SAMD21E17A__) || defined(__SAMD21E18A__) || defined(__SAMD51G19A__)
#include "platforms/arm/d21/led_sysdefs_arm_d21.h"
#elif defined(ESP8266)
#include "platforms/esp/8266/led_sysdefs_esp8266.h"
#elif defined(ESP32)
#include "platforms/esp/32/led_sysdefs_esp32.h"
#elif defined(FASTLED_NO_PLATFORM)
// No-op stubs to enable compilation
typedef int RwReg;
typedef int RoReg;

#include <chrono>
#include <thread>

inline uint32_t micros() {
  std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(
      std::chrono::system_clock::now().time_since_epoch()
  );
  return (uint64_t) ms.count() & 0xffffffff;
}

inline uint32_t millis() {
  std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::system_clock::now().time_since_epoch()
  );
  return (uint64_t) ms.count() & 0xffffffff;
}
inline uint32_t get_millisecond_timer() { return millis(); }

inline void delay(int ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

inline void yield() {
  std::this_thread::yield();
}

#define F_CPU 100000000L
#define FASTLED_NO_PINMAP
//#define DATA_RATE_MHZ(X) (((100000000L / 1000000L) / X))
//#define DATA_RATE_KHZ(X) (((100000000L / 1000L) / X))

#else
// AVR platforms
#include "platforms/avr/led_sysdefs_avr.h"
#endif

#ifndef FASTLED_NAMESPACE_BEGIN
#define FASTLED_NAMESPACE_BEGIN
#define FASTLED_NAMESPACE_END
#define FASTLED_USING_NAMESPACE
#endif

// Arduino.h needed for convenience functions digitalPinToPort/BitMask/portOutputRegister and the pinMode methods.
#ifdef ARDUINO
#include <Arduino.h>
#endif

#define CLKS_PER_US (F_CPU/1000000)

#endif
