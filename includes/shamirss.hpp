#ifndef __SHAMIRSS__
#define __SHAMIRSS__

#include <vector>

#include "field_secp256r1.hpp"

typedef Field_secp256r1_n FIELD_n;

typedef struct Share
{
    FIELD_n idx;
    FIELD_n val;
    Share() {}
    Share(FIELD_n idx, FIELD_n val)
    {
        this->idx = idx;
        this->val = val;
    }
} share_t;

typedef std::vector<share_t> share_v_t;
typedef std::vector<FIELD_n> field_v_t;

class ShamirSS
{
private:
    int i;
    FIELD_n evalPoly(FIELD_n x, field_v_t& poly);
public:
    ShamirSS();
    ~ShamirSS();

    share_v_t getShares(size_t t, size_t n, FIELD_n secret);
    FIELD_n reconSecret(share_v_t shares);
};

#endif