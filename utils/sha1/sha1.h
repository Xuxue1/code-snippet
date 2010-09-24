
class SHA1Context
{
public:

private:
  uint32_t total[2];
  uint32_t state[5];
  uint8_t buffer[64];
};

void sha1_starts( SSHA1Context *ctx );
void sha1_update( SSHA1Context *ctx,
          const uint8_t *input,
          uint32_t length );
void sha1_finish( SSHA1Context *ctx,
          uint8_t digest[20] );
void sha1_hmac( const uint8_t *key,
        uint32_t keylen,
        const uint8_t *buf,
        uint32_t buflen,
                uint8_t digest[20] );
