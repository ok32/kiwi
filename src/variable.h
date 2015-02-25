#pragma once

#include <kiwi/kiwi.h>

using namespace kiwi;

extern "C" {
    Variable* Variable_create( const char* name ) {
        return new Variable( name );
    }

    void Variable_destroy( Variable* variable ) {
        delete variable;
    }

    const char* Variable_name( Variable* variable ) {
        return variable->name().c_str();
    }

    void Variable_setName( Variable* variable, const char* name ) {
        variable->setName(name);
    }

    double Variable_value( Variable* variable ) {
        return variable->value();
    }

    void Variable_setValue( Variable* variable, double value ) {
        variable->setValue( value );
    }

    bool Variable_equals( Variable* variable, const Variable* other ) {
        return variable->equals(*other);
    }

    bool Variable_less( Variable* variable, const Variable* other ) {
        return variable < other;
    }
}
