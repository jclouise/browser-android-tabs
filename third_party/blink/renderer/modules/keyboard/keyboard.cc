// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/modules/keyboard/keyboard.h"

#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/modules/keyboard/keyboard_layout.h"
#include "third_party/blink/renderer/modules/keyboard/keyboard_lock.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"

namespace blink {

Keyboard::Keyboard(ExecutionContext* context)
    : keyboard_lock_(MakeGarbageCollected<KeyboardLock>(context)),
      keyboard_layout_(MakeGarbageCollected<KeyboardLayout>(context)) {}

Keyboard::~Keyboard() = default;

ScriptPromise Keyboard::lock(ScriptState* state,
                             const Vector<String>& keycodes) {
  return keyboard_lock_->lock(state, keycodes);
}

void Keyboard::unlock(ScriptState* state) {
  keyboard_lock_->unlock(state);
}

ScriptPromise Keyboard::getLayoutMap(ScriptState* state) {
  return keyboard_layout_->GetKeyboardLayoutMap(state);
}

void Keyboard::Trace(blink::Visitor* visitor) {
  visitor->Trace(keyboard_lock_);
  visitor->Trace(keyboard_layout_);
  ScriptWrappable::Trace(visitor);
}

}  // namespace blink
