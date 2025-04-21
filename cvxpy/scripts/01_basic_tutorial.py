import cvxpy as cp

# Create two scalar optimization variable
x = cp.Variable()
y = cp.Variable()

# Create two constraints
constraints = [x+y==1, x-y>=1]

# From objective
obj = cp.Minimize((x-y)**2)

# From and solver problem
prob = cp.Problem(obj, constraints)
prob.solve() # Return the optimal value
print("status: ", prob.status)
print("optimal value", prob.value)
print("optimal var", x.value, y.value)
