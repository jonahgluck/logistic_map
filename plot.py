import matplotlib.pyplot as plt

# Load Lyapunov exponents data from file
data = []
with open("build/lyapunov_exponents.txt", "r") as file:
    for line in file:
        r, lyapunov = map(float, line.strip().split("\t"))
        data.append((r, lyapunov))

# Extract r and Lyapunov exponents
r_values = [item[0] for item in data]
lyapunov_values = [item[1] for item in data]

# Plot Lyapunov exponents vs. r
plt.figure(figsize=(10, 6))
plt.plot(r_values, lyapunov_values, color='blue', marker='.', linestyle='-', linewidth=2, markersize=4)
plt.xlabel('r')
plt.ylabel('Lyapunov Exponent')
plt.title('Lyapunov Exponents vs. r')
plt.grid(True)
plt.show()

