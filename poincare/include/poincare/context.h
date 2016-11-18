#ifndef POINCARE_CONTEXT_H
#define POINCARE_CONTEXT_H

#include <poincare/expression.h>
#include <poincare/symbol.h>
#include <poincare/float.h>

class Integer;

//TODO: We should probably make a COPY of the expressions we store

class Context {
  public:
    Context();
    virtual const Expression * expressionForSymbol(const Symbol * symbol);
    void setExpressionForSymbolName(Expression * expression, const Symbol * symbol);
    static constexpr uint16_t k_maxNumberOfScalarExpressions = 26;
    static constexpr uint16_t k_maxNumberOfListExpressions = 10;
    static constexpr uint16_t k_maxNumberOfMatrixExpressions = 10;
  private:
    int symbolIndex(const Symbol * symbol) const;
    Expression * m_expressions[k_maxNumberOfScalarExpressions];
    static Float * defaultExpression();
};

#endif
