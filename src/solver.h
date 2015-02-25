#pragma once

#include <kiwi/kiwi.h>

#include "errors.h"

using namespace kiwi;

extern "C" {
    Solver* Solver_create() {
        return new Solver();
    }

    void Solver_destroy( Solver* solver ) {
        delete solver;
    }

    errors::ErrCode Solver_addConstraint( Solver* solver, const Constraint* constraint ) {
        try {
            solver->addConstraint( *constraint );
        } catch (...) {
            return errors::handle();
        }
        return errors::NO_ERROR;
    }

    errors::ErrCode Solver_removeConstraint( Solver* solver, const Constraint* constraint ) {
        try {
            solver->removeConstraint( *constraint );
        } catch (...) {
            return errors::handle();
        }
        return errors::NO_ERROR;
    }

    bool Solver_hasConstraint( Solver* solver, const Constraint* constraint ) {
        return solver->hasConstraint( *constraint );
    }

    errors::ErrCode Solver_addEditVariable( Solver* solver, const Variable* variable, double strength ) {
        try {
            solver->addEditVariable( *variable, strength );
        } catch (...) {
            return errors::handle();
        }
        return errors::NO_ERROR;
    }

    errors::ErrCode Solver_removeEditVariable( Solver* solver, const Variable* variable ) {
        try {
            solver->removeEditVariable( *variable );
        } catch (...) {
            return errors::handle();
        }
        return errors::NO_ERROR;
    }

    bool Solver_hasEditVariable( Solver* solver, const Variable* variable ) {
        return solver->hasEditVariable( *variable );
    }

    errors::ErrCode Solver_suggestValue( Solver* solver, const Variable* variable, double value ) {
        try {
            solver->suggestValue( *variable, value );
        } catch (...) {
            return errors::handle();
        }
        return errors::NO_ERROR;
    }

    void Solver_updateVariables( Solver* solver ) {
        solver->updateVariables();
    }

    void Solver_reset( Solver* solver ) {
        solver->reset();
    }

    void Solver_dump( Solver* solver ) {
        solver->dump();
    }
}
