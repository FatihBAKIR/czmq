/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "QmlZhttpResponse.h"


///
//  Send a response to a request.
//  Returns 0 if successful and -1 otherwise.
int QmlZhttpResponse::send (QmlZsock *sock, void **connection) {
    return zhttp_response_send (self, sock->self, connection);
};

///
//  Receive a response from zhttp_client.
//  On success return 0, -1 otherwise.
//
//  Recv returns the two user arguments which was provided with the request.
//  The reason for two, is to be able to pass around the server connection when forwarding requests or both a callback function and an argument.
int QmlZhttpResponse::recv (QmlZhttpClient *client, void **arg, void **arg2) {
    return zhttp_response_recv (self, client->self, arg, arg2);
};

///
//  Get the response content type
const QString QmlZhttpResponse::contentType () {
    return QString (zhttp_response_content_type (self));
};

///
//  Set the content type of the response.
void QmlZhttpResponse::setContentType (const QString &value) {
    zhttp_response_set_content_type (self, value.toUtf8().data());
};

///
//  Get the status code of the response.
uint32_t QmlZhttpResponse::statusCode () {
    return zhttp_response_status_code (self);
};

///
//  Set the status code of the response.
void QmlZhttpResponse::setStatusCode (uint32_t statusCode) {
    zhttp_response_set_status_code (self, statusCode);
};

///
//  Get the headers of the response.
QmlZhash *QmlZhttpResponse::headers () {
    QmlZhash *retQ_ = new QmlZhash ();
    retQ_->self = zhttp_response_headers (self);
    return retQ_;
};

///
//  Get the content length of the response
size_t QmlZhttpResponse::contentLength () {
    return zhttp_response_content_length (self);
};

///
//  Get the content of the response.
const QString QmlZhttpResponse::content () {
    return QString (zhttp_response_content (self));
};

///
//  Get the content of the response.
QString QmlZhttpResponse::getContent () {
    char *retStr_ = zhttp_response_get_content (self);
    QString retQStr_ = QString (retStr_);
    free (retStr_);
    return retQStr_;
};

///
//  Set the content of the response.
//  Content must by dynamically allocated string.
//  Takes ownership of the content.
void QmlZhttpResponse::setContent (QString content) {
    zhttp_response_set_content (self, content.toUtf8().data());
};

///
//  Set the content of the response.
//  The content is assumed to be constant-memory and will therefore not be copied or deallocated in any way.
void QmlZhttpResponse::setContentConst (const QString &content) {
    zhttp_response_set_content_const (self, content.toUtf8().data());
};

///
//  Set the content to NULL
void QmlZhttpResponse::resetContent () {
    zhttp_response_reset_content (self);
};


QObject* QmlZhttpResponse::qmlAttachedProperties(QObject* object) {
    return new QmlZhttpResponseAttached(object);
}


///
//  Self test of this class.
void QmlZhttpResponseAttached::test (bool verbose) {
    zhttp_response_test (verbose);
};

///
//  Create a new zhttp_response.
QmlZhttpResponse *QmlZhttpResponseAttached::construct () {
    QmlZhttpResponse *qmlSelf = new QmlZhttpResponse ();
    qmlSelf->self = zhttp_response_new ();
    return qmlSelf;
};

///
//  Destroy the zhttp_response.
void QmlZhttpResponseAttached::destruct (QmlZhttpResponse *qmlSelf) {
    zhttp_response_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
