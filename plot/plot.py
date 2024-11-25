import matplotlib.pyplot as plt

# Sample data for the first graph (list of pairs)
data1 = [(1, 20.004), (2, 11.228), (4, 6.578), (8, 4.220)]
# Unpack the data into x and y coordinates
x1, y1 = zip(*data1)

# Constant line value
constant_value = 19.964

# Create a new figure and axis
plt.figure(figsize=(10, 6))

# Plot the first graph
plt.plot(x1, y1, marker='o', color='b', label='Parallel implementation')  # Blue line with circle markers

# Plot the constant line
x_constant = range(1, 9)
plt.plot(x_constant, [constant_value] * len(x_constant), color='r', linestyle='--', label='Sequential implementation')  # Red dashed line

# Adding title and labels
plt.title('Bitonic sort benchmarking')
plt.xlabel('OMP_NUM_THREADS value')
plt.ylabel('Execution time, seconds')

# Adding a legend
plt.legend()

# Show grid
plt.grid()

# Display the plot
plt.savefig('plot/performance.png')
plt.show()
