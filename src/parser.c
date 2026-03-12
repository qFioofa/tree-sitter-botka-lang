#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 11
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 14
#define ALIAS_COUNT 0
#define TOKEN_COUNT 8
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_ATstart = 2,
  anon_sym_ATu043du0430u0447u0430u043bu043e = 3,
  anon_sym_ATend = 4,
  anon_sym_ATu043au043eu043du0435u0446 = 5,
  aux_sym_program_error_parsing_token1 = 6,
  sym_comment = 7,
  sym_source_file = 8,
  sym_program_start = 9,
  sym_program_end = 10,
  sym__content = 11,
  sym_program_error_parsing = 12,
  aux_sym_source_file_repeat1 = 13,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_ATstart] = "@start",
  [anon_sym_ATu043du0430u0447u0430u043bu043e] = "@\u043d\u0430\u0447\u0430\u043b\u043e",
  [anon_sym_ATend] = "@end",
  [anon_sym_ATu043au043eu043du0435u0446] = "@\u043a\u043e\u043d\u0435\u0446",
  [aux_sym_program_error_parsing_token1] = "program_error_parsing_token1",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym_program_start] = "program_start",
  [sym_program_end] = "program_end",
  [sym__content] = "_content",
  [sym_program_error_parsing] = "program_error_parsing",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_ATstart] = anon_sym_ATstart,
  [anon_sym_ATu043du0430u0447u0430u043bu043e] = anon_sym_ATu043du0430u0447u0430u043bu043e,
  [anon_sym_ATend] = anon_sym_ATend,
  [anon_sym_ATu043au043eu043du0435u0446] = anon_sym_ATu043au043eu043du0435u0446,
  [aux_sym_program_error_parsing_token1] = aux_sym_program_error_parsing_token1,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym_program_start] = sym_program_start,
  [sym_program_end] = sym_program_end,
  [sym__content] = sym__content,
  [sym_program_error_parsing] = sym_program_error_parsing,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_ATstart] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATu043du0430u0447u0430u043bu043e] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATend] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATu043au043eu043du0435u0446] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_program_error_parsing_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_program_start] = {
    .visible = true,
    .named = true,
  },
  [sym_program_end] = {
    .visible = true,
    .named = true,
  },
  [sym__content] = {
    .visible = false,
    .named = true,
  },
  [sym_program_error_parsing] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '/') ADVANCE(1);
      if (lookahead == '@') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x410 <= lookahead && lookahead <= 0x44f)) ADVANCE(33);
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(3);
      if (lookahead == '/') ADVANCE(35);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '/') ADVANCE(34);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == '@') ADVANCE(8);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(31);
      if (lookahead != 0) ADVANCE(32);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(10);
      END_STATE();
    case 6:
      if (lookahead == 'd') ADVANCE(25);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(9);
      if (lookahead == 's') ADVANCE(11);
      if (lookahead == 0x43a) ADVANCE(18);
      if (lookahead == 0x43d) ADVANCE(13);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(9);
      if (lookahead == 0x43a) ADVANCE(18);
      END_STATE();
    case 9:
      if (lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 10:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == 't') ADVANCE(5);
      END_STATE();
    case 12:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 13:
      if (lookahead == 0x430) ADVANCE(21);
      END_STATE();
    case 14:
      if (lookahead == 0x430) ADVANCE(16);
      END_STATE();
    case 15:
      if (lookahead == 0x435) ADVANCE(20);
      END_STATE();
    case 16:
      if (lookahead == 0x43b) ADVANCE(19);
      END_STATE();
    case 17:
      if (lookahead == 0x43d) ADVANCE(15);
      END_STATE();
    case 18:
      if (lookahead == 0x43e) ADVANCE(17);
      END_STATE();
    case 19:
      if (lookahead == 0x43e) ADVANCE(24);
      END_STATE();
    case 20:
      if (lookahead == 0x446) ADVANCE(26);
      END_STATE();
    case 21:
      if (lookahead == 0x447) ADVANCE(14);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_ATstart);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_ATu043du0430u0447u0430u043bu043e);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_ATend);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_ATu043au043eu043du0435u0446);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_program_error_parsing_token1);
      if (lookahead == '\n') ADVANCE(32);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead != 0) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_program_error_parsing_token1);
      if (lookahead == '*') ADVANCE(30);
      if (lookahead == '/') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(32);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_program_error_parsing_token1);
      if (lookahead == '*') ADVANCE(29);
      if (lookahead == '/') ADVANCE(32);
      if (lookahead == '@') ADVANCE(3);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_program_error_parsing_token1);
      if (lookahead == '*') ADVANCE(29);
      if (lookahead == '@') ADVANCE(3);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_program_error_parsing_token1);
      if (lookahead == '/') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(32);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_program_error_parsing_token1);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x410 <= lookahead && lookahead <= 0x44f)) ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(35);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 4},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 4},
  [6] = {.lex_state = 4},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_ATstart] = ACTIONS(1),
    [anon_sym_ATu043du0430u0447u0430u043bu043e] = ACTIONS(1),
    [anon_sym_ATend] = ACTIONS(1),
    [anon_sym_ATu043au043eu043du0435u0446] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(7),
    [sym_program_start] = STATE(2),
    [anon_sym_ATstart] = ACTIONS(5),
    [anon_sym_ATu043du0430u0447u0430u043bu043e] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
  },
  [2] = {
    [sym_program_end] = STATE(9),
    [sym__content] = STATE(3),
    [sym_program_error_parsing] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [anon_sym_ATend] = ACTIONS(7),
    [anon_sym_ATu043au043eu043du0435u0446] = ACTIONS(7),
    [aux_sym_program_error_parsing_token1] = ACTIONS(9),
    [sym_comment] = ACTIONS(11),
  },
  [3] = {
    [sym_program_end] = STATE(10),
    [sym__content] = STATE(4),
    [sym_program_error_parsing] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [anon_sym_ATend] = ACTIONS(7),
    [anon_sym_ATu043au043eu043du0435u0446] = ACTIONS(7),
    [aux_sym_program_error_parsing_token1] = ACTIONS(9),
    [sym_comment] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(17), 1,
      aux_sym_program_error_parsing_token1,
    ACTIONS(20), 1,
      sym_comment,
    ACTIONS(15), 2,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
    STATE(4), 3,
      sym__content,
      sym_program_error_parsing,
      aux_sym_source_file_repeat1,
  [16] = 1,
    ACTIONS(23), 4,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      aux_sym_program_error_parsing_token1,
      sym_comment,
  [23] = 1,
    ACTIONS(25), 4,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      aux_sym_program_error_parsing_token1,
      sym_comment,
  [30] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
  [37] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
  [44] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
  [51] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 16,
  [SMALL_STATE(6)] = 23,
  [SMALL_STATE(7)] = 30,
  [SMALL_STATE(8)] = 37,
  [SMALL_STATE(9)] = 44,
  [SMALL_STATE(10)] = 51,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [20] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_program_start, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_program_error_parsing, 1, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program_end, 1, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_botka(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
