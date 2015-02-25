#pragma once

#include <kiwi/kiwi.h>

using namespace kiwi;

extern "C" {
    Expression* Expression_createWithConstant( double constant ) {
        return new Expression( constant );
    }

    Expression* Expression_create() {
        return Expression_createWithConstant(0.0);
    }

    Expression* Expression_createFromVariable( const Variable* variable ) {
        return new Expression( *variable );
    }

    void Expression_destroy( Expression* expression ) {
        delete expression;
    }

    double Expression_constant( Expression* expression ) {
        return expression->constant();
    }

    double Expression_value( Expression* expression ) {
        return expression->value();
    }
}
