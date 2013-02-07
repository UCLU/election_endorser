<?php

/**
 * @file
 * Builds placeholder replacement tokens for endorser data.
 */

/**
 * Implements hook_token_info().
 */
function election_endorser_token_info() {

  $info['types']['election_endorser-field-value'] = array(
    'name' => t('Endorser field values'),
    'description' => t('Tokens related to endorser field values.'),
    'needs-data' => 'election_endorser-field-value',
    'field-value' => TRUE,
    'module' => 'election_endorser',
  );
  $info['tokens']['election_endorser-field-value']['name'] = array(
    'name' => t('Name'),
    'description' => t("The endorser's name."),
  );
  $info['tokens']['election_endorser-field-value']['mail'] = array(
    'name' => t('E-mail address'),
    'description' => t("The endorser's e-mail address."),
    'type' => 'mail',
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function election_endorser_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $language_code = isset($options['language']) ? $options['language']->language : NULL;

  if ($type == 'election_endorser-field-value' && !empty($data['item'])) {
    $item = $data['item'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'name':
          $name = $item['name'];
          $replacements[$original] = $sanitize ? check_plain($name) : $name;
          break;

        case 'mail':
          $mail = $item['mail'];
          $replacements[$original] = $sanitize ? check_plain($mail) : $mail;
          break;

      }
    }
  }

  return $replacements;
}
