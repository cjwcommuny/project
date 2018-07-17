#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include "Common/etlbase.h"
#include "Common/matrix.h"
#include "Notification/notification.h"
#include "Notification/outputnumericalresultnotification_viewmodel.h"
#include "Viewmodel/viewmodel.h"



class Model: public Proxy_PropertyNotification<Model>
{
public:
    Model();
    void notifyResult();
    void notifyFailure();
    bool transmit_expression(std::string str);
    std::shared_ptr<std::string> getExpression() {return expression;}
private:
    std::shared_ptr<std::string> expression;
    template <typename T, typename sizeT = size_t>
    std::shared_ptr<matrix<T, sizeT>> SingleRowmatrixParser(std::string expression);
    template <typename T, typename sizeT = size_t>
    std::shared_ptr<matrix<T, sizeT>> matrixParser(std::string expression);
};

#endif // MODEL_H