#pragma once

namespace errors {

enum ErrCode {
    NO_ERROR = 0,
    UNKNOWN_ERROR = -1,

    UNSATISFIABLE_CONSTRAINT = 1,
    UNKNOWN_CONSTRAINT = 2,
    DUPLICATE_CONSTRAINT = 3,
    UNKNOWN_EDIT_VARIABLE = 4,
    DUPLICATE_EDIT_VARIABLE = 5,
    BAD_REQUIRED_STRENGTH = 6,
    INTERNAL_SOLVER_ERROR = 7
};

ErrCode handle() {
    try {
        throw;
    } catch (kiwi::UnsatisfiableConstraint) {
        return UNSATISFIABLE_CONSTRAINT;
    } catch (kiwi::UnknownConstraint) {
        return UNKNOWN_CONSTRAINT;
    } catch (kiwi::DuplicateConstraint) {
        return DUPLICATE_CONSTRAINT;
    } catch (kiwi::UnknownEditVariable) {
        return UNKNOWN_EDIT_VARIABLE;
    } catch (kiwi::DuplicateEditVariable) {
        return DUPLICATE_EDIT_VARIABLE;
    } catch (kiwi::BadRequiredStrength) {
        return BAD_REQUIRED_STRENGTH;
    } catch (kiwi::InternalSolverError) {
        return INTERNAL_SOLVER_ERROR;
    } catch (...) {
        return UNKNOWN_ERROR;
    }
}

} // namespace errors
