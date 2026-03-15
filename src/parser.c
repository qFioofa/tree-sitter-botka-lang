#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 68
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 72
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_ATstart = 2,
  anon_sym_ATu043du0430u0447u0430u043bu043e = 3,
  anon_sym_ATend = 4,
  anon_sym_ATu043au043eu043du0435u0446 = 5,
  anon_sym_SEMI = 6,
  anon_sym_if = 7,
  anon_sym_u0435u0441u043bu0438 = 8,
  anon_sym_LPAREN = 9,
  anon_sym_RPAREN = 10,
  anon_sym_LBRACE = 11,
  anon_sym_not = 12,
  anon_sym_u043du0435 = 13,
  anon_sym_RBRACE = 14,
  anon_sym_coin = 15,
  anon_sym_u043cu043eu043du0435u0442u0430 = 16,
  anon_sym_obj = 17,
  anon_sym_u043eu0431u044au0435u043au0442 = 18,
  anon_sym_space = 19,
  anon_sym_u043fu0443u0441u0442u043e = 20,
  anon_sym_else = 21,
  anon_sym_u0438u043du0430u0447u0435 = 22,
  anon_sym_while = 23,
  anon_sym_u043fu043eu043au0430 = 24,
  anon_sym_for = 25,
  anon_sym_u0434u043bu044f = 26,
  anon_sym_times = 27,
  anon_sym_u0440u0430u0437 = 28,
  anon_sym_forward = 29,
  anon_sym_u0432u043fu0435u0440u0435u0434 = 30,
  anon_sym_backwards = 31,
  anon_sym_u043du0430u0437u0430u0434 = 32,
  anon_sym_right = 33,
  anon_sym_u0432u043fu0440u0430u0432u043e = 34,
  anon_sym_left = 35,
  anon_sym_u0432u043bu0435u0432u043e = 36,
  sym_number = 37,
  sym_positive_number = 38,
  sym_single_line_comment = 39,
  sym_multi_line_comment = 40,
  sym_source_file = 41,
  sym_program_start = 42,
  sym_program_end = 43,
  sym_statement = 44,
  sym_empty_statement = 45,
  sym_if_statement = 46,
  sym_if_keyword = 47,
  sym_condition = 48,
  sym_condition_modifier = 49,
  sym_instance = 50,
  sym_coin_instance = 51,
  sym_obj_instance = 52,
  sym_space_instance = 53,
  sym_else_keyword = 54,
  sym_else_if_clause = 55,
  sym_else_clause = 56,
  sym_block = 57,
  sym_while_statement = 58,
  sym_while_keyword = 59,
  sym_for_statement = 60,
  sym_for_keyword = 61,
  sym_for_condition = 62,
  sym_times_keyword = 63,
  sym_action_statement = 64,
  sym_action_type = 65,
  sym_forward_action = 66,
  sym_backwards_action = 67,
  sym_right_action = 68,
  sym_left_action = 69,
  aux_sym_source_file_repeat1 = 70,
  aux_sym_if_statement_repeat1 = 71,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_ATstart] = "@start",
  [anon_sym_ATu043du0430u0447u0430u043bu043e] = "@\u043d\u0430\u0447\u0430\u043b\u043e",
  [anon_sym_ATend] = "@end",
  [anon_sym_ATu043au043eu043du0435u0446] = "@\u043a\u043e\u043d\u0435\u0446",
  [anon_sym_SEMI] = ";",
  [anon_sym_if] = "if",
  [anon_sym_u0435u0441u043bu0438] = "\u0435\u0441\u043b\u0438",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_not] = "not",
  [anon_sym_u043du0435] = "\u043d\u0435",
  [anon_sym_RBRACE] = "}",
  [anon_sym_coin] = "coin",
  [anon_sym_u043cu043eu043du0435u0442u0430] = "\u043c\u043e\u043d\u0435\u0442\u0430",
  [anon_sym_obj] = "obj",
  [anon_sym_u043eu0431u044au0435u043au0442] = "\u043e\u0431\u044a\u0435\u043a\u0442",
  [anon_sym_space] = "space",
  [anon_sym_u043fu0443u0441u0442u043e] = "\u043f\u0443\u0441\u0442\u043e",
  [anon_sym_else] = "else",
  [anon_sym_u0438u043du0430u0447u0435] = "\u0438\u043d\u0430\u0447\u0435",
  [anon_sym_while] = "while",
  [anon_sym_u043fu043eu043au0430] = "\u043f\u043e\u043a\u0430",
  [anon_sym_for] = "for",
  [anon_sym_u0434u043bu044f] = "\u0434\u043b\u044f",
  [anon_sym_times] = "times",
  [anon_sym_u0440u0430u0437] = "\u0440\u0430\u0437",
  [anon_sym_forward] = "forward",
  [anon_sym_u0432u043fu0435u0440u0435u0434] = "\u0432\u043f\u0435\u0440\u0435\u0434",
  [anon_sym_backwards] = "backwards",
  [anon_sym_u043du0430u0437u0430u0434] = "\u043d\u0430\u0437\u0430\u0434",
  [anon_sym_right] = "right",
  [anon_sym_u0432u043fu0440u0430u0432u043e] = "\u0432\u043f\u0440\u0430\u0432\u043e",
  [anon_sym_left] = "left",
  [anon_sym_u0432u043bu0435u0432u043e] = "\u0432\u043b\u0435\u0432\u043e",
  [sym_number] = "number",
  [sym_positive_number] = "positive_number",
  [sym_single_line_comment] = "single_line_comment",
  [sym_multi_line_comment] = "multi_line_comment",
  [sym_source_file] = "source_file",
  [sym_program_start] = "program_start",
  [sym_program_end] = "program_end",
  [sym_statement] = "statement",
  [sym_empty_statement] = "empty_statement",
  [sym_if_statement] = "if_statement",
  [sym_if_keyword] = "if_keyword",
  [sym_condition] = "condition",
  [sym_condition_modifier] = "condition_modifier",
  [sym_instance] = "instance",
  [sym_coin_instance] = "coin_instance",
  [sym_obj_instance] = "obj_instance",
  [sym_space_instance] = "space_instance",
  [sym_else_keyword] = "else_keyword",
  [sym_else_if_clause] = "else_if_clause",
  [sym_else_clause] = "else_clause",
  [sym_block] = "block",
  [sym_while_statement] = "while_statement",
  [sym_while_keyword] = "while_keyword",
  [sym_for_statement] = "for_statement",
  [sym_for_keyword] = "for_keyword",
  [sym_for_condition] = "for_condition",
  [sym_times_keyword] = "times_keyword",
  [sym_action_statement] = "action_statement",
  [sym_action_type] = "action_type",
  [sym_forward_action] = "forward_action",
  [sym_backwards_action] = "backwards_action",
  [sym_right_action] = "right_action",
  [sym_left_action] = "left_action",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_if_statement_repeat1] = "if_statement_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_ATstart] = anon_sym_ATstart,
  [anon_sym_ATu043du0430u0447u0430u043bu043e] = anon_sym_ATu043du0430u0447u0430u043bu043e,
  [anon_sym_ATend] = anon_sym_ATend,
  [anon_sym_ATu043au043eu043du0435u0446] = anon_sym_ATu043au043eu043du0435u0446,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_u0435u0441u043bu0438] = anon_sym_u0435u0441u043bu0438,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_u043du0435] = anon_sym_u043du0435,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_coin] = anon_sym_coin,
  [anon_sym_u043cu043eu043du0435u0442u0430] = anon_sym_u043cu043eu043du0435u0442u0430,
  [anon_sym_obj] = anon_sym_obj,
  [anon_sym_u043eu0431u044au0435u043au0442] = anon_sym_u043eu0431u044au0435u043au0442,
  [anon_sym_space] = anon_sym_space,
  [anon_sym_u043fu0443u0441u0442u043e] = anon_sym_u043fu0443u0441u0442u043e,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_u0438u043du0430u0447u0435] = anon_sym_u0438u043du0430u0447u0435,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_u043fu043eu043au0430] = anon_sym_u043fu043eu043au0430,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_u0434u043bu044f] = anon_sym_u0434u043bu044f,
  [anon_sym_times] = anon_sym_times,
  [anon_sym_u0440u0430u0437] = anon_sym_u0440u0430u0437,
  [anon_sym_forward] = anon_sym_forward,
  [anon_sym_u0432u043fu0435u0440u0435u0434] = anon_sym_u0432u043fu0435u0440u0435u0434,
  [anon_sym_backwards] = anon_sym_backwards,
  [anon_sym_u043du0430u0437u0430u0434] = anon_sym_u043du0430u0437u0430u0434,
  [anon_sym_right] = anon_sym_right,
  [anon_sym_u0432u043fu0440u0430u0432u043e] = anon_sym_u0432u043fu0440u0430u0432u043e,
  [anon_sym_left] = anon_sym_left,
  [anon_sym_u0432u043bu0435u0432u043e] = anon_sym_u0432u043bu0435u0432u043e,
  [sym_number] = sym_number,
  [sym_positive_number] = sym_positive_number,
  [sym_single_line_comment] = sym_single_line_comment,
  [sym_multi_line_comment] = sym_multi_line_comment,
  [sym_source_file] = sym_source_file,
  [sym_program_start] = sym_program_start,
  [sym_program_end] = sym_program_end,
  [sym_statement] = sym_statement,
  [sym_empty_statement] = sym_empty_statement,
  [sym_if_statement] = sym_if_statement,
  [sym_if_keyword] = sym_if_keyword,
  [sym_condition] = sym_condition,
  [sym_condition_modifier] = sym_condition_modifier,
  [sym_instance] = sym_instance,
  [sym_coin_instance] = sym_coin_instance,
  [sym_obj_instance] = sym_obj_instance,
  [sym_space_instance] = sym_space_instance,
  [sym_else_keyword] = sym_else_keyword,
  [sym_else_if_clause] = sym_else_if_clause,
  [sym_else_clause] = sym_else_clause,
  [sym_block] = sym_block,
  [sym_while_statement] = sym_while_statement,
  [sym_while_keyword] = sym_while_keyword,
  [sym_for_statement] = sym_for_statement,
  [sym_for_keyword] = sym_for_keyword,
  [sym_for_condition] = sym_for_condition,
  [sym_times_keyword] = sym_times_keyword,
  [sym_action_statement] = sym_action_statement,
  [sym_action_type] = sym_action_type,
  [sym_forward_action] = sym_forward_action,
  [sym_backwards_action] = sym_backwards_action,
  [sym_right_action] = sym_right_action,
  [sym_left_action] = sym_left_action,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_if_statement_repeat1] = aux_sym_if_statement_repeat1,
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
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u0435u0441u043bu0438] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u043du0435] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_coin] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u043cu043eu043du0435u0442u0430] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_obj] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u043eu0431u044au0435u043au0442] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_space] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u043fu0443u0441u0442u043e] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u0438u043du0430u0447u0435] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u043fu043eu043au0430] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u0434u043bu044f] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_times] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u0440u0430u0437] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_forward] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u0432u043fu0435u0440u0435u0434] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_backwards] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u043du0430u0437u0430u0434] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_right] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u0432u043fu0440u0430u0432u043e] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_left] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u0432u043bu0435u0432u043e] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_positive_number] = {
    .visible = true,
    .named = true,
  },
  [sym_single_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_multi_line_comment] = {
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
  [sym_statement] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_empty_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_if_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_condition] = {
    .visible = true,
    .named = true,
  },
  [sym_condition_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_instance] = {
    .visible = true,
    .named = true,
  },
  [sym_coin_instance] = {
    .visible = true,
    .named = true,
  },
  [sym_obj_instance] = {
    .visible = true,
    .named = true,
  },
  [sym_space_instance] = {
    .visible = true,
    .named = true,
  },
  [sym_else_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_else_if_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_else_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_while_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_while_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_for_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_for_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_for_condition] = {
    .visible = true,
    .named = true,
  },
  [sym_times_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_action_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_action_type] = {
    .visible = true,
    .named = true,
  },
  [sym_forward_action] = {
    .visible = true,
    .named = true,
  },
  [sym_backwards_action] = {
    .visible = true,
    .named = true,
  },
  [sym_right_action] = {
    .visible = true,
    .named = true,
  },
  [sym_left_action] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_if_statement_repeat1] = {
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
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(24);
      ADVANCE_MAP(
        '(', 30,
        ')', 31,
        '+', 22,
        '-', 22,
        '/', 1,
        '0', 34,
        ';', 29,
        '@', 8,
        '{', 32,
        '}', 33,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x410 <= lookahead && lookahead <= 0x44f)) ADVANCE(39);
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(3);
      if (lookahead == '/') ADVANCE(37);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '+') ADVANCE(23);
      if (lookahead == '/') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(36);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(1);
      if (lookahead == '0') ADVANCE(34);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(35);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(10);
      END_STATE();
    case 7:
      if (lookahead == 'd') ADVANCE(27);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(9);
      if (lookahead == 's') ADVANCE(11);
      if (lookahead == 0x43a) ADVANCE(18);
      if (lookahead == 0x43d) ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 10:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == 't') ADVANCE(6);
      END_STATE();
    case 12:
      if (lookahead == 't') ADVANCE(25);
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
      if (lookahead == 0x43e) ADVANCE(26);
      END_STATE();
    case 20:
      if (lookahead == 0x446) ADVANCE(28);
      END_STATE();
    case 21:
      if (lookahead == 0x447) ADVANCE(14);
      END_STATE();
    case 22:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(35);
      END_STATE();
    case 23:
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(36);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_ATstart);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_ATu043du0430u0447u0430u043bu043e);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_ATend);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_ATu043au043eu043du0435u0446);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_number);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_positive_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_single_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_multi_line_comment);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x410 <= lookahead && lookahead <= 0x44f)) ADVANCE(39);
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
      ADVANCE_MAP(
        'b', 1,
        'c', 2,
        'e', 3,
        'f', 4,
        'i', 5,
        'l', 6,
        'n', 7,
        'o', 8,
        'r', 9,
        's', 10,
        't', 11,
        'w', 12,
        0x432, 13,
        0x434, 14,
        0x435, 15,
        0x438, 16,
        0x43c, 17,
        0x43d, 18,
        0x43e, 19,
        0x43f, 20,
        0x440, 21,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 2:
      if (lookahead == 'o') ADVANCE(23);
      END_STATE();
    case 3:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 4:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 5:
      if (lookahead == 'f') ADVANCE(26);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(28);
      END_STATE();
    case 8:
      if (lookahead == 'b') ADVANCE(29);
      END_STATE();
    case 9:
      if (lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 10:
      if (lookahead == 'p') ADVANCE(31);
      END_STATE();
    case 11:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 12:
      if (lookahead == 'h') ADVANCE(33);
      END_STATE();
    case 13:
      if (lookahead == 0x43b) ADVANCE(34);
      if (lookahead == 0x43f) ADVANCE(35);
      END_STATE();
    case 14:
      if (lookahead == 0x43b) ADVANCE(36);
      END_STATE();
    case 15:
      if (lookahead == 0x441) ADVANCE(37);
      END_STATE();
    case 16:
      if (lookahead == 0x43d) ADVANCE(38);
      END_STATE();
    case 17:
      if (lookahead == 0x43e) ADVANCE(39);
      END_STATE();
    case 18:
      if (lookahead == 0x430) ADVANCE(40);
      if (lookahead == 0x435) ADVANCE(41);
      END_STATE();
    case 19:
      if (lookahead == 0x431) ADVANCE(42);
      END_STATE();
    case 20:
      if (lookahead == 0x43e) ADVANCE(43);
      if (lookahead == 0x443) ADVANCE(44);
      END_STATE();
    case 21:
      if (lookahead == 0x430) ADVANCE(45);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(46);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(47);
      END_STATE();
    case 24:
      if (lookahead == 's') ADVANCE(48);
      END_STATE();
    case 25:
      if (lookahead == 'r') ADVANCE(49);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 27:
      if (lookahead == 'f') ADVANCE(50);
      END_STATE();
    case 28:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 29:
      if (lookahead == 'j') ADVANCE(52);
      END_STATE();
    case 30:
      if (lookahead == 'g') ADVANCE(53);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(54);
      END_STATE();
    case 32:
      if (lookahead == 'm') ADVANCE(55);
      END_STATE();
    case 33:
      if (lookahead == 'i') ADVANCE(56);
      END_STATE();
    case 34:
      if (lookahead == 0x435) ADVANCE(57);
      END_STATE();
    case 35:
      if (lookahead == 0x435) ADVANCE(58);
      if (lookahead == 0x440) ADVANCE(59);
      END_STATE();
    case 36:
      if (lookahead == 0x44f) ADVANCE(60);
      END_STATE();
    case 37:
      if (lookahead == 0x43b) ADVANCE(61);
      END_STATE();
    case 38:
      if (lookahead == 0x430) ADVANCE(62);
      END_STATE();
    case 39:
      if (lookahead == 0x43d) ADVANCE(63);
      END_STATE();
    case 40:
      if (lookahead == 0x437) ADVANCE(64);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_u043du0435);
      END_STATE();
    case 42:
      if (lookahead == 0x44a) ADVANCE(65);
      END_STATE();
    case 43:
      if (lookahead == 0x43a) ADVANCE(66);
      END_STATE();
    case 44:
      if (lookahead == 0x441) ADVANCE(67);
      END_STATE();
    case 45:
      if (lookahead == 0x437) ADVANCE(68);
      END_STATE();
    case 46:
      if (lookahead == 'k') ADVANCE(69);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_for);
      if (lookahead == 'w') ADVANCE(72);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(73);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_obj);
      END_STATE();
    case 53:
      if (lookahead == 'h') ADVANCE(74);
      END_STATE();
    case 54:
      if (lookahead == 'c') ADVANCE(75);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(77);
      END_STATE();
    case 57:
      if (lookahead == 0x432) ADVANCE(78);
      END_STATE();
    case 58:
      if (lookahead == 0x440) ADVANCE(79);
      END_STATE();
    case 59:
      if (lookahead == 0x430) ADVANCE(80);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_u0434u043bu044f);
      END_STATE();
    case 61:
      if (lookahead == 0x438) ADVANCE(81);
      END_STATE();
    case 62:
      if (lookahead == 0x447) ADVANCE(82);
      END_STATE();
    case 63:
      if (lookahead == 0x435) ADVANCE(83);
      END_STATE();
    case 64:
      if (lookahead == 0x430) ADVANCE(84);
      END_STATE();
    case 65:
      if (lookahead == 0x435) ADVANCE(85);
      END_STATE();
    case 66:
      if (lookahead == 0x430) ADVANCE(86);
      END_STATE();
    case 67:
      if (lookahead == 0x442) ADVANCE(87);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_u0440u0430u0437);
      END_STATE();
    case 69:
      if (lookahead == 'w') ADVANCE(88);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_coin);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 72:
      if (lookahead == 'a') ADVANCE(89);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_left);
      END_STATE();
    case 74:
      if (lookahead == 't') ADVANCE(90);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 76:
      if (lookahead == 's') ADVANCE(92);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(93);
      END_STATE();
    case 78:
      if (lookahead == 0x43e) ADVANCE(94);
      END_STATE();
    case 79:
      if (lookahead == 0x435) ADVANCE(95);
      END_STATE();
    case 80:
      if (lookahead == 0x432) ADVANCE(96);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_u0435u0441u043bu0438);
      END_STATE();
    case 82:
      if (lookahead == 0x435) ADVANCE(97);
      END_STATE();
    case 83:
      if (lookahead == 0x442) ADVANCE(98);
      END_STATE();
    case 84:
      if (lookahead == 0x434) ADVANCE(99);
      END_STATE();
    case 85:
      if (lookahead == 0x43a) ADVANCE(100);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_u043fu043eu043au0430);
      END_STATE();
    case 87:
      if (lookahead == 0x43e) ADVANCE(101);
      END_STATE();
    case 88:
      if (lookahead == 'a') ADVANCE(102);
      END_STATE();
    case 89:
      if (lookahead == 'r') ADVANCE(103);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_right);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_space);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_times);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_u0432u043bu0435u0432u043e);
      END_STATE();
    case 95:
      if (lookahead == 0x434) ADVANCE(104);
      END_STATE();
    case 96:
      if (lookahead == 0x43e) ADVANCE(105);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_u0438u043du0430u0447u0435);
      END_STATE();
    case 98:
      if (lookahead == 0x430) ADVANCE(106);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_u043du0430u0437u0430u0434);
      END_STATE();
    case 100:
      if (lookahead == 0x442) ADVANCE(107);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_u043fu0443u0441u0442u043e);
      END_STATE();
    case 102:
      if (lookahead == 'r') ADVANCE(108);
      END_STATE();
    case 103:
      if (lookahead == 'd') ADVANCE(109);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_u0432u043fu0435u0440u0435u0434);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_u0432u043fu0440u0430u0432u043e);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_u043cu043eu043du0435u0442u0430);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_u043eu0431u044au0435u043au0442);
      END_STATE();
    case 108:
      if (lookahead == 'd') ADVANCE(110);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_forward);
      END_STATE();
    case 110:
      if (lookahead == 's') ADVANCE(111);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_backwards);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 5},
  [50] = {.lex_state = 5},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 5},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 5},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 5},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 5},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_ATstart] = ACTIONS(1),
    [anon_sym_ATu043du0430u0447u0430u043bu043e] = ACTIONS(1),
    [anon_sym_ATend] = ACTIONS(1),
    [anon_sym_ATu043au043eu043du0435u0446] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_u0435u0441u043bu0438] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_u043du0435] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_coin] = ACTIONS(1),
    [anon_sym_u043cu043eu043du0435u0442u0430] = ACTIONS(1),
    [anon_sym_obj] = ACTIONS(1),
    [anon_sym_u043eu0431u044au0435u043au0442] = ACTIONS(1),
    [anon_sym_space] = ACTIONS(1),
    [anon_sym_u043fu0443u0441u0442u043e] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_u0438u043du0430u0447u0435] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_u043fu043eu043au0430] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_u0434u043bu044f] = ACTIONS(1),
    [anon_sym_times] = ACTIONS(1),
    [anon_sym_u0440u0430u0437] = ACTIONS(1),
    [anon_sym_forward] = ACTIONS(1),
    [anon_sym_u0432u043fu0435u0440u0435u0434] = ACTIONS(1),
    [anon_sym_backwards] = ACTIONS(1),
    [anon_sym_u043du0430u0437u0430u0434] = ACTIONS(1),
    [anon_sym_right] = ACTIONS(1),
    [anon_sym_u0432u043fu0440u0430u0432u043e] = ACTIONS(1),
    [anon_sym_left] = ACTIONS(1),
    [anon_sym_u0432u043bu0435u0432u043e] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_positive_number] = ACTIONS(1),
    [sym_single_line_comment] = ACTIONS(3),
    [sym_multi_line_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(59),
    [sym_program_start] = STATE(2),
    [sym_program_end] = STATE(67),
    [sym_statement] = STATE(3),
    [sym_empty_statement] = STATE(18),
    [sym_if_statement] = STATE(15),
    [sym_if_keyword] = STATE(35),
    [sym_while_statement] = STATE(15),
    [sym_while_keyword] = STATE(37),
    [sym_for_statement] = STATE(15),
    [sym_for_keyword] = STATE(34),
    [sym_action_statement] = STATE(16),
    [sym_action_type] = STATE(62),
    [sym_forward_action] = STATE(65),
    [sym_backwards_action] = STATE(65),
    [sym_right_action] = STATE(65),
    [sym_left_action] = STATE(65),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_ATstart] = ACTIONS(7),
    [anon_sym_ATu043du0430u0447u0430u043bu043e] = ACTIONS(7),
    [anon_sym_ATend] = ACTIONS(9),
    [anon_sym_ATu043au043eu043du0435u0446] = ACTIONS(9),
    [anon_sym_SEMI] = ACTIONS(11),
    [anon_sym_if] = ACTIONS(13),
    [anon_sym_u0435u0441u043bu0438] = ACTIONS(13),
    [anon_sym_while] = ACTIONS(15),
    [anon_sym_u043fu043eu043au0430] = ACTIONS(15),
    [anon_sym_for] = ACTIONS(17),
    [anon_sym_u0434u043bu044f] = ACTIONS(19),
    [anon_sym_forward] = ACTIONS(21),
    [anon_sym_u0432u043fu0435u0440u0435u0434] = ACTIONS(21),
    [anon_sym_backwards] = ACTIONS(23),
    [anon_sym_u043du0430u0437u0430u0434] = ACTIONS(23),
    [anon_sym_right] = ACTIONS(25),
    [anon_sym_u0432u043fu0440u0430u0432u043e] = ACTIONS(25),
    [anon_sym_left] = ACTIONS(27),
    [anon_sym_u0432u043bu0435u0432u043e] = ACTIONS(27),
    [sym_single_line_comment] = ACTIONS(3),
    [sym_multi_line_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 22,
    ACTIONS(11), 1,
      anon_sym_SEMI,
    ACTIONS(17), 1,
      anon_sym_for,
    ACTIONS(19), 1,
      anon_sym_u0434u043bu044f,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    STATE(16), 1,
      sym_action_statement,
    STATE(18), 1,
      sym_empty_statement,
    STATE(34), 1,
      sym_for_keyword,
    STATE(35), 1,
      sym_if_keyword,
    STATE(37), 1,
      sym_while_keyword,
    STATE(57), 1,
      sym_program_end,
    STATE(62), 1,
      sym_action_type,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(9), 2,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
    ACTIONS(13), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
    ACTIONS(15), 2,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
    ACTIONS(21), 2,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
    ACTIONS(23), 2,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
    ACTIONS(25), 2,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
    ACTIONS(27), 2,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
    STATE(4), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(15), 3,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
    STATE(65), 4,
      sym_forward_action,
      sym_backwards_action,
      sym_right_action,
      sym_left_action,
  [81] = 22,
    ACTIONS(11), 1,
      anon_sym_SEMI,
    ACTIONS(17), 1,
      anon_sym_for,
    ACTIONS(19), 1,
      anon_sym_u0434u043bu044f,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    STATE(16), 1,
      sym_action_statement,
    STATE(18), 1,
      sym_empty_statement,
    STATE(34), 1,
      sym_for_keyword,
    STATE(35), 1,
      sym_if_keyword,
    STATE(37), 1,
      sym_while_keyword,
    STATE(57), 1,
      sym_program_end,
    STATE(62), 1,
      sym_action_type,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(9), 2,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
    ACTIONS(13), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
    ACTIONS(15), 2,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
    ACTIONS(21), 2,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
    ACTIONS(23), 2,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
    ACTIONS(25), 2,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
    ACTIONS(27), 2,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
    STATE(5), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(15), 3,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
    STATE(65), 4,
      sym_forward_action,
      sym_backwards_action,
      sym_right_action,
      sym_left_action,
  [162] = 22,
    ACTIONS(11), 1,
      anon_sym_SEMI,
    ACTIONS(17), 1,
      anon_sym_for,
    ACTIONS(19), 1,
      anon_sym_u0434u043bu044f,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    STATE(16), 1,
      sym_action_statement,
    STATE(18), 1,
      sym_empty_statement,
    STATE(34), 1,
      sym_for_keyword,
    STATE(35), 1,
      sym_if_keyword,
    STATE(37), 1,
      sym_while_keyword,
    STATE(52), 1,
      sym_program_end,
    STATE(62), 1,
      sym_action_type,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(9), 2,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
    ACTIONS(13), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
    ACTIONS(15), 2,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
    ACTIONS(21), 2,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
    ACTIONS(23), 2,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
    ACTIONS(25), 2,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
    ACTIONS(27), 2,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
    STATE(5), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(15), 3,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
    STATE(65), 4,
      sym_forward_action,
      sym_backwards_action,
      sym_right_action,
      sym_left_action,
  [243] = 20,
    ACTIONS(35), 1,
      anon_sym_SEMI,
    ACTIONS(44), 1,
      anon_sym_for,
    ACTIONS(47), 1,
      anon_sym_u0434u043bu044f,
    STATE(16), 1,
      sym_action_statement,
    STATE(18), 1,
      sym_empty_statement,
    STATE(34), 1,
      sym_for_keyword,
    STATE(35), 1,
      sym_if_keyword,
    STATE(37), 1,
      sym_while_keyword,
    STATE(62), 1,
      sym_action_type,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(38), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
    ACTIONS(41), 2,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
    ACTIONS(50), 2,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
    ACTIONS(53), 2,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
    ACTIONS(56), 2,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
    ACTIONS(59), 2,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
    STATE(5), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(15), 3,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
    ACTIONS(33), 4,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_RBRACE,
    STATE(65), 4,
      sym_forward_action,
      sym_backwards_action,
      sym_right_action,
      sym_left_action,
  [320] = 20,
    ACTIONS(11), 1,
      anon_sym_SEMI,
    ACTIONS(17), 1,
      anon_sym_for,
    ACTIONS(19), 1,
      anon_sym_u0434u043bu044f,
    ACTIONS(62), 1,
      anon_sym_RBRACE,
    STATE(16), 1,
      sym_action_statement,
    STATE(18), 1,
      sym_empty_statement,
    STATE(34), 1,
      sym_for_keyword,
    STATE(35), 1,
      sym_if_keyword,
    STATE(37), 1,
      sym_while_keyword,
    STATE(62), 1,
      sym_action_type,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(13), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
    ACTIONS(15), 2,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
    ACTIONS(21), 2,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
    ACTIONS(23), 2,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
    ACTIONS(25), 2,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
    ACTIONS(27), 2,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
    STATE(7), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(15), 3,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
    STATE(65), 4,
      sym_forward_action,
      sym_backwards_action,
      sym_right_action,
      sym_left_action,
  [394] = 20,
    ACTIONS(11), 1,
      anon_sym_SEMI,
    ACTIONS(17), 1,
      anon_sym_for,
    ACTIONS(19), 1,
      anon_sym_u0434u043bu044f,
    ACTIONS(64), 1,
      anon_sym_RBRACE,
    STATE(16), 1,
      sym_action_statement,
    STATE(18), 1,
      sym_empty_statement,
    STATE(34), 1,
      sym_for_keyword,
    STATE(35), 1,
      sym_if_keyword,
    STATE(37), 1,
      sym_while_keyword,
    STATE(62), 1,
      sym_action_type,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(13), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
    ACTIONS(15), 2,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
    ACTIONS(21), 2,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
    ACTIONS(23), 2,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
    ACTIONS(25), 2,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
    ACTIONS(27), 2,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
    STATE(5), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(15), 3,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
    STATE(65), 4,
      sym_forward_action,
      sym_backwards_action,
      sym_right_action,
      sym_left_action,
  [468] = 7,
    ACTIONS(70), 1,
      anon_sym_for,
    STATE(23), 1,
      sym_else_clause,
    STATE(28), 1,
      sym_else_keyword,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(68), 2,
      anon_sym_else,
      anon_sym_u0438u043du0430u0447u0435,
    STATE(10), 2,
      sym_else_if_clause,
      aux_sym_if_statement_repeat1,
    ACTIONS(66), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [510] = 7,
    ACTIONS(74), 1,
      anon_sym_for,
    STATE(21), 1,
      sym_else_clause,
    STATE(28), 1,
      sym_else_keyword,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(68), 2,
      anon_sym_else,
      anon_sym_u0438u043du0430u0447u0435,
    STATE(8), 2,
      sym_else_if_clause,
      aux_sym_if_statement_repeat1,
    ACTIONS(72), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [552] = 6,
    ACTIONS(81), 1,
      anon_sym_for,
    STATE(29), 1,
      sym_else_keyword,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(78), 2,
      anon_sym_else,
      anon_sym_u0438u043du0430u0447u0435,
    STATE(10), 2,
      sym_else_if_clause,
      aux_sym_if_statement_repeat1,
    ACTIONS(76), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [591] = 3,
    ACTIONS(85), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(83), 20,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_else,
      anon_sym_u0438u043du0430u0447u0435,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [621] = 3,
    ACTIONS(89), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(87), 20,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_else,
      anon_sym_u0438u043du0430u0447u0435,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [651] = 3,
    ACTIONS(93), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(91), 20,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_else,
      anon_sym_u0438u043du0430u0447u0435,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [681] = 3,
    ACTIONS(97), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(95), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [709] = 3,
    ACTIONS(101), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(99), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [737] = 3,
    ACTIONS(101), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(99), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [765] = 3,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(103), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [793] = 3,
    ACTIONS(101), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(99), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [821] = 3,
    ACTIONS(109), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(107), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [849] = 3,
    ACTIONS(113), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(111), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [877] = 3,
    ACTIONS(70), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(66), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [905] = 3,
    ACTIONS(117), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(115), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [933] = 3,
    ACTIONS(121), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(119), 18,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_RBRACE,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [961] = 3,
    ACTIONS(125), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(123), 17,
      ts_builtin_sym_end,
      anon_sym_ATend,
      anon_sym_ATu043au043eu043du0435u0446,
      anon_sym_SEMI,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_while,
      anon_sym_u043fu043eu043au0430,
      anon_sym_u0434u043bu044f,
      anon_sym_forward,
      anon_sym_u0432u043fu0435u0440u0435u0434,
      anon_sym_backwards,
      anon_sym_u043du0430u0437u0430u0434,
      anon_sym_right,
      anon_sym_u0432u043fu0440u0430u0432u043e,
      anon_sym_left,
      anon_sym_u0432u043bu0435u0432u043e,
  [988] = 6,
    STATE(47), 1,
      sym_instance,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(127), 2,
      anon_sym_coin,
      anon_sym_u043cu043eu043du0435u0442u0430,
    ACTIONS(129), 2,
      anon_sym_obj,
      anon_sym_u043eu0431u044au0435u043au0442,
    ACTIONS(131), 2,
      anon_sym_space,
      anon_sym_u043fu0443u0441u0442u043e,
    STATE(48), 3,
      sym_coin_instance,
      sym_obj_instance,
      sym_space_instance,
  [1013] = 2,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(133), 6,
      anon_sym_coin,
      anon_sym_u043cu043eu043du0435u0442u0430,
      anon_sym_obj,
      anon_sym_u043eu0431u044au0435u043au0442,
      anon_sym_space,
      anon_sym_u043fu0443u0441u0442u043e,
  [1026] = 2,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(135), 6,
      anon_sym_coin,
      anon_sym_u043cu043eu043du0435u0442u0430,
      anon_sym_obj,
      anon_sym_u043eu0431u044au0435u043au0442,
      anon_sym_space,
      anon_sym_u043fu0443u0441u0442u043e,
  [1039] = 5,
    ACTIONS(137), 1,
      anon_sym_LBRACE,
    STATE(22), 1,
      sym_block,
    STATE(38), 1,
      sym_if_keyword,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(13), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
  [1057] = 3,
    STATE(38), 1,
      sym_if_keyword,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(13), 2,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
  [1069] = 3,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(139), 2,
      anon_sym_not,
      anon_sym_u043du0435,
  [1081] = 3,
    STATE(56), 1,
      sym_times_keyword,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(143), 2,
      anon_sym_times,
      anon_sym_u0440u0430u0437,
  [1093] = 2,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
    ACTIONS(145), 3,
      anon_sym_if,
      anon_sym_u0435u0441u043bu0438,
      anon_sym_LBRACE,
  [1103] = 3,
    ACTIONS(137), 1,
      anon_sym_LBRACE,
    STATE(9), 1,
      sym_block,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1114] = 3,
    ACTIONS(147), 1,
      anon_sym_LPAREN,
    STATE(36), 1,
      sym_for_condition,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1125] = 3,
    ACTIONS(149), 1,
      anon_sym_LPAREN,
    STATE(33), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1136] = 3,
    ACTIONS(137), 1,
      anon_sym_LBRACE,
    STATE(17), 1,
      sym_block,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1147] = 3,
    ACTIONS(149), 1,
      anon_sym_LPAREN,
    STATE(41), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1158] = 3,
    ACTIONS(149), 1,
      anon_sym_LPAREN,
    STATE(40), 1,
      sym_condition,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1169] = 3,
    ACTIONS(151), 1,
      anon_sym_LBRACE,
    STATE(25), 1,
      sym_condition_modifier,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1180] = 3,
    ACTIONS(137), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      sym_block,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1191] = 3,
    ACTIONS(137), 1,
      anon_sym_LBRACE,
    STATE(19), 1,
      sym_block,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1202] = 2,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1210] = 2,
    ACTIONS(155), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1218] = 2,
    ACTIONS(157), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1226] = 2,
    ACTIONS(159), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1234] = 2,
    ACTIONS(161), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1242] = 2,
    ACTIONS(163), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1250] = 2,
    ACTIONS(165), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1258] = 2,
    ACTIONS(167), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1266] = 2,
    ACTIONS(169), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1274] = 2,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1282] = 2,
    ACTIONS(173), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1290] = 2,
    ACTIONS(175), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1298] = 2,
    ACTIONS(177), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1306] = 2,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1314] = 2,
    ACTIONS(181), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1322] = 2,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1330] = 2,
    ACTIONS(183), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1338] = 2,
    ACTIONS(185), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1346] = 2,
    ACTIONS(187), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1354] = 2,
    ACTIONS(189), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1362] = 2,
    ACTIONS(191), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1370] = 2,
    ACTIONS(193), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1378] = 2,
    ACTIONS(195), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1386] = 2,
    ACTIONS(197), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1394] = 2,
    ACTIONS(199), 1,
      sym_positive_number,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
  [1402] = 2,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_single_line_comment,
      sym_multi_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 81,
  [SMALL_STATE(4)] = 162,
  [SMALL_STATE(5)] = 243,
  [SMALL_STATE(6)] = 320,
  [SMALL_STATE(7)] = 394,
  [SMALL_STATE(8)] = 468,
  [SMALL_STATE(9)] = 510,
  [SMALL_STATE(10)] = 552,
  [SMALL_STATE(11)] = 591,
  [SMALL_STATE(12)] = 621,
  [SMALL_STATE(13)] = 651,
  [SMALL_STATE(14)] = 681,
  [SMALL_STATE(15)] = 709,
  [SMALL_STATE(16)] = 737,
  [SMALL_STATE(17)] = 765,
  [SMALL_STATE(18)] = 793,
  [SMALL_STATE(19)] = 821,
  [SMALL_STATE(20)] = 849,
  [SMALL_STATE(21)] = 877,
  [SMALL_STATE(22)] = 905,
  [SMALL_STATE(23)] = 933,
  [SMALL_STATE(24)] = 961,
  [SMALL_STATE(25)] = 988,
  [SMALL_STATE(26)] = 1013,
  [SMALL_STATE(27)] = 1026,
  [SMALL_STATE(28)] = 1039,
  [SMALL_STATE(29)] = 1057,
  [SMALL_STATE(30)] = 1069,
  [SMALL_STATE(31)] = 1081,
  [SMALL_STATE(32)] = 1093,
  [SMALL_STATE(33)] = 1103,
  [SMALL_STATE(34)] = 1114,
  [SMALL_STATE(35)] = 1125,
  [SMALL_STATE(36)] = 1136,
  [SMALL_STATE(37)] = 1147,
  [SMALL_STATE(38)] = 1158,
  [SMALL_STATE(39)] = 1169,
  [SMALL_STATE(40)] = 1180,
  [SMALL_STATE(41)] = 1191,
  [SMALL_STATE(42)] = 1202,
  [SMALL_STATE(43)] = 1210,
  [SMALL_STATE(44)] = 1218,
  [SMALL_STATE(45)] = 1226,
  [SMALL_STATE(46)] = 1234,
  [SMALL_STATE(47)] = 1242,
  [SMALL_STATE(48)] = 1250,
  [SMALL_STATE(49)] = 1258,
  [SMALL_STATE(50)] = 1266,
  [SMALL_STATE(51)] = 1274,
  [SMALL_STATE(52)] = 1282,
  [SMALL_STATE(53)] = 1290,
  [SMALL_STATE(54)] = 1298,
  [SMALL_STATE(55)] = 1306,
  [SMALL_STATE(56)] = 1314,
  [SMALL_STATE(57)] = 1322,
  [SMALL_STATE(58)] = 1330,
  [SMALL_STATE(59)] = 1338,
  [SMALL_STATE(60)] = 1346,
  [SMALL_STATE(61)] = 1354,
  [SMALL_STATE(62)] = 1362,
  [SMALL_STATE(63)] = 1370,
  [SMALL_STATE(64)] = 1378,
  [SMALL_STATE(65)] = 1386,
  [SMALL_STATE(66)] = 1394,
  [SMALL_STATE(67)] = 1402,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 4, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 4, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 3, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 3, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_statement_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_if_statement_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_statement_repeat1, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_if_clause, 4, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_if_clause, 4, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_empty_statement, 1, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_empty_statement, 1, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_statement, 3, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_statement, 3, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_statement, 3, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_statement, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_statement, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_statement, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_clause, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_else_clause, 2, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 5, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 5, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program_start, 1, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_program_start, 1, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_modifier, 3, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_modifier, 2, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_keyword, 1, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_coin_instance, 1, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_obj_instance, 1, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_space_instance, 1, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instance, 1, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_backwards_action, 1, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_right_action, 1, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_keyword, 1, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_keyword, 1, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_left_action, 1, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_times_keyword, 1, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition, 4, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_forward_action, 1, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_keyword, 1, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program_end, 1, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_condition, 4, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_type, 1, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
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
