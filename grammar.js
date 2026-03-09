/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "botka_lang",

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ => "hello"
  }
});
