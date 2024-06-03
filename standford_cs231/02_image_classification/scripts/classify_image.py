import numpy as np


# Nearest Neighbor
#d(i1, i2) = integer|I1_p - I2_p|

class NearestNeighbor:
    def __init__(self):
        pass
    
    def train(self, X ,y):
        """X is N X D where each row is an example. Y is 1-dim of Size N"""
        self.Xtr = X
        self.ytr = y
        
    def predict(model, X):
        """X is N x D where each row is an example we wish to predict label for"""
        num_test = X.shape[0]
        # lets make shure that the output type matches the input types
        yPred = np.zeros(num_test, dtype = self.ytr.dtype)

        # loop over all test rows
        for i in xrange[num_test]:
            # fill the nearest training image to the i'th test image
            # using the L1 distance (sum of absolute value differences)
            distances = np.sum(np.abs(self.Xtr - X[i,:]), axis=1)
            min_index = np.argmin(distances) # get the index with smallest distance
            Ypred[i] = self.ytr[min_index] # predict the label of the nearest example
        
        return Ypred

