"""
Implements commonly used kernel functions

Source for implementation: http://www.csie.ntu.edu.tw/~cjlin/papers/guide/guide.pdf

"""
import math
import numpy as np

########################

def linear_kernel(x, y):
    """
    Returns xT . Y

    """
    return (x.T).dot(y)

def polynomial_kernel(x, y, gamma, r, d):
    """
    Returns (gamma * xT . y + r)^d
    
    This kernel is more popular in natural language
    processing.

    """
    return (gamma * ((x.T).dot(y)) + r ) ** d


def radial_basis_function(x, y, gamma):
    """
    Returns e ^ (-1 * gammma * ||x - y|| ^ 2)

    """
    dist_x_y = np.linalg.norm(x - y)
    return math.e ** (-1 * gamma * (dist ** 2))

def sigmoid(x, y, r):
    """
    Returns tanh(gamma * xT . y + r)

    """
    return math.tanh(gamma * ((x.T).dot(y)) + r)

