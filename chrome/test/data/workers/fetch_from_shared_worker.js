// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

self.onconnect = e => {
  const port = e.ports[0];
  port.onmessage = async e => {
    const response = await fetch(e.data.url);
    if (!response.ok) {
      port.postMessage(`Bad response: ${responses.statusText}`);
      return;
    }
    const text = await response.text();
    port.postMessage(text);
  }
};
