#pragma once

#include <kiwi/kiwi.h>

using namespace kiwi;

extern "C" {
    Constraint* Constraint_create( const Expression* expression,
                                                RelationalOperator op,
                                                double strength ) {
        return new Constraint( *expression, op, strength );
    }

    void Constraint_destroy( Constraint* constraint ) {
        delete constraint;
    }

    const Expression* Constraint_expression( Constraint* constraint ) {
        return &constraint->expression();
    }

    RelationalOperator Constraint_op( Constraint* constraint ) {
        return constraint->op();
    }

    double Constraint_strength( Constraint* constraint ) {
        return constraint->strength();
    }
}
