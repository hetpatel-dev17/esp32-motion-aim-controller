# Debugging Journal

This document records key issues encountered during development.

## Serial Monitor Output Error

Problem:
Serial monitor displayed unreadable characters.

Cause:
Baud rate mismatch.

Fix:
Set both code and serial monitor to the same baud rate.

## Cursor Jitter

Problem:
Cursor movement was unstable.

Cause:
Raw gyroscope data contains noise.

Fix:
Added deadzone filtering and motion smoothing.

## Axis Inversion

Problem:
Controller movement did not match cursor direction.

Fix:
Implemented axis remapping and inversion system.

