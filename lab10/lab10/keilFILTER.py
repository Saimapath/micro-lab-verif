import numpy as np
from scipy.signal import firwin

# Constants
cutoff_frequency = 2000  # Hz
sampling_frequency = 200000  # 200 ksps (from datasheet)
filter_order = 8

# Step 1: Calculate the normalized cutoff frequency
nyquist_frequency = sampling_frequency / 2
normalized_cutoff = cutoff_frequency / nyquist_frequency

# Step 3: Design the filter using firwin
filter_coefficients = firwin(filter_order, normalized_cutoff)

# Display the coefficients
print("Filter Coefficients:", filter_coefficients)
