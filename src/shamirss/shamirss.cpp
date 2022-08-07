#include "shamirss.hpp"



ShamirSS::ShamirSS()
{

}

ShamirSS::~ShamirSS()
{

}
FIELD_n ShamirSS::evalPoly(FIELD_n x, field_v_t& poly)
{
    FIELD_n y;
    FIELD_n temp = FIELD_n(1);
 
    for (auto coeff : poly) {
        y = (y + (coeff * temp));
        temp = (temp * x);
    }
    return y;
}
share_v_t ShamirSS::getShares(size_t t, size_t n, FIELD_n secret)
{
    field_v_t coefs = {secret};
    share_v_t shares;
    for (size_t i = 0; i < t-1; i++)
    {
        coefs.push_back(FIELD_n((rand()+1) %100));
    }

    for (size_t i = 1; i <= n; i++)
    {
        share_t share;
        share.idx = FIELD_n(i);
        share.val = evalPoly(share.idx, coefs);
        shares.push_back(share);
    }       
    return shares;
    
}

FIELD_n ShamirSS::reconSecret(share_v_t shares)
{
    FIELD_n res;

    for (size_t i = 0; i < shares.size(); i++)
    {
        FIELD_n numerator = FIELD_n(1);
        FIELD_n denominator = FIELD_n(1);

        for (size_t j = 0; j < shares.size(); j++)
        {
            if(i!=j)
            {
                numerator *= shares[j].idx;
                denominator *= shares[j].idx - shares[i].idx;
            }
        }
        res += shares[i].val * numerator / denominator;
    }
    
    return res;
    
    
}