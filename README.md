# Description

This is an implementation of Shamir's Secret Sharing scheme. 

The repository includes:
- A library for operations inside fields of prime order (we use the prime order of secp256r1 curve)
- The secret sharing protocol 

# Building
```
mkdir build
cd build && cmake ..
make
ctest --verbose
```
