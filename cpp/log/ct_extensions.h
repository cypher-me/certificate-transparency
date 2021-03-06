#ifndef CERT_TRANS_LOG_CT_EXTENSIONS_H_
#define CERT_TRANS_LOG_CT_EXTENSIONS_H_

#include <openssl/asn1t.h>

namespace cert_trans {

// One-time initializer for loading CT-specific certificate extensions.
void LoadCtExtensions();

// Defines structure for redacted label count to hold a stack of integers
typedef struct RedactedLabelCount_st {
  STACK_OF(ASN1_INTEGER) * redacted_labels;
} REDACTED_LABEL_COUNT;

// Defines asn.1 for redacted label count as a SEQUENCE OF ASN1_INTEGER
ASN1_SEQUENCE(REDACTED_LABEL_COUNT) = {
    ASN1_SEQUENCE_OF(REDACTED_LABEL_COUNT, redacted_labels, ASN1_INTEGER),
} ASN1_SEQUENCE_END(REDACTED_LABEL_COUNT);

// The official V1 CT OIDs are in OpenSSL.

// V2 numerical identifiers
// You must call LoadCtExtensions() for these to work.
extern int NID_ctPrecertificateRedactedLabelCount;
extern int NID_ctNameConstraintNologIntermediateCa;
// V2 payload content type
extern int NID_ctV2CmsPayloadContentType;

// Name constrained intermediate CA may not be logged
extern const char kNameConstraintNologIntermediateOID[];
// Content type name for Precert V2
extern const char kV2PrecertPayloadContentType[];

}  // namespace cert_trans

#endif  // CERT_TRANS_LOG_CT_EXTENSIONS_H_
