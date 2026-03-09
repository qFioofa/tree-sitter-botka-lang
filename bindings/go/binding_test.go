package tree_sitter_botka_lang_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-botka_lang"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_botka_lang.Language())
	if language == nil {
		t.Errorf("Error loading BotkaLang grammar")
	}
}
