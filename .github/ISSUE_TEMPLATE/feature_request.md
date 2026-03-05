---
name: Feature Request
about: Suggest a new feature or improvement
title: "[Feature] "
labels: enhancement
assignees: ''
---

## Summary

Provide a short description of the proposed feature.

Example:
Add support for constant folding in the optimizer.

---

## Motivation

Why is this feature needed?

- What problem does it solve?
- What use case does it enable?

Example:
Currently the compiler generates unnecessary instructions for constant expressions.  
Constant folding would reduce runtime cost and improve optimization quality.

---

## Proposed Design

Describe how the feature should work.

Questions to consider:

- What part of the system will it affect?
- What APIs or components need to change?
- What data structures or algorithms might be required?

Example:

- Add a constant folding pass after AST construction.
- Traverse AST nodes and evaluate constant expressions.
- Replace constant expressions with literal values.

---

## Alternatives Considered

Describe other approaches you considered.

Example:
- Performing constant folding during parsing.
- Running a peephole optimization on generated IR.

---

## Impact

What parts of the project will this affect?

- [ ] Parser
- [ ] AST
- [ ] Semantic Analysis
- [ ] Optimizer
- [ ] Code Generation
- [ ] Documentation
- [ ] Tests

---

## Additional Context

Add diagrams, pseudocode, references, or examples if helpful.
