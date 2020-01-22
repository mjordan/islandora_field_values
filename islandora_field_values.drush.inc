<?php

/**
 * @file
 * Drush command for querying Solr for all values in a field.
 */

/**
 * Implements hook_drush_command().
 */
function islandora_field_values_drush_command() {
  return array(
    'islandora-field-values-get' => array(
      'aliases' => array('ifvget'),
      'description' => dt('Gets unique values used in a field, plus number of occurances of each value.'),
      'drupal dependencies' => array(
        'islandora',
        'islandora_solr',
      ),
      'options' => array(
        'fieldname' => array(
          'description' => dt('The Solr field name.'),
          'required' => TRUE,
        ),
        'output_file' => array(
          'description' => dt('Absolute or relative path to the output file.'),
          'required' => TRUE,
        ),
        'remove_line_breaks' => array(
          'description' => dt('Removes line breaks from values.'),
          'value' => 'optional',
        ),
      ),
      'examples' => array(
        'Get all values in mods_genre_ms' => 'drush islandora-field-values-get --fieldname=mods_genre_ms --output_file=/tmp/output.txt',
      ),
    ),
  );
}

function drush_islandora_field_values_get() {
  module_load_include('inc', 'islandora_field_values', 'includes/utilities');
  $fieldname = trim(drush_get_option('fieldname'));
  $output_file_path = trim(drush_get_option('output_file'));
  if ($results = islandora_field_values_query_solr($fieldname)) {
    islandora_field_values_write_output($results);
    drush_log(dt('Results for field !fieldname written to !path (!num unique values).', array(
      '!num' => count($results),
      '!fieldname' => $fieldname,
      '!path' => $output_file_path,
    )), 'ok');
  }
  else {
    drush_log(dt('No results for field !fieldname', array(
      '!fieldname' => $fieldname,
    )), 'warning');
  }
}
