from pynq import Overlay

# Load the FPGA bitstream
overlay = Overlay("mul_accel.bit")

# Access the HLS accelerator
mul = overlay.mul_accel_0

# Input values
a = 5.0
b = 6.0

# Call the accelerator
result = mul.call(a, b)

print("a =", a)
print("b =", b)
print("Result =", result)
