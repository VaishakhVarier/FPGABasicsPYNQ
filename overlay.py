#needs updated reg_mapping, just an example

from pynq import Overlay, allocate
import numpy as np

# Load FPGA overlay
overlay = Overlay("matmul.bit")

# Access accelerator
matmul = overlay.matmul_16x16_0

# Display hardware register map
print(matmul.register_map)

# Allocate DDR buffers
A = allocate(shape=(16, 16), dtype=np.float32)
B = allocate(shape=(16, 16), dtype=np.float32)
C = allocate(shape=(16, 16), dtype=np.float32)

# Initialize matrices
A[:] = np.arange(256, dtype=np.float32).reshape(16, 16)
B[:] = np.eye(16, dtype=np.float32)

# Clear output
C[:] = 0

# Give accelerator the physical addresses
matmul.register_map.A = A.physical_address
matmul.register_map.B = B.physical_address
matmul.register_map.C = C.physical_address

# Start accelerator
matmul.register_map.CTRL.AP_START = 1

# Wait for completion
while not matmul.register_map.CTRL.AP_DONE:
    pass

# Display result
print("Matrix A:")
print(A)

print("\nMatrix B:")
print(B)

print("\nMatrix C = A × B:")
print(C)

# Verify
expected = np.matmul(A, B)

print("\nVerification:", np.allclose(C, expected))