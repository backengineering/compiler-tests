// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for
// full license information.

#include <windows.h>
#include "seh.h"

char test[] = "SEH0015.c";
int perfect;

int main() {
  LONG Counter;

  Counter = 0;

  try {
    try {
      /* set counter = 1 */
      Counter += 1;
    }
    finally {
      /* set counter = 2 */
      Counter += 1;
      goto t10;
    }
  }
  finally {
    /* set counter = 3 */
    Counter += 1;
  }

t10:
  ;

  if (Counter != 3) {
    printf("TEST 15 FAILED. Counter = %d\n\r", Counter);
    return -1;
  }

  return 0;
}
