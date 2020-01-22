<?php
/**
 * @file
 * Utility functions.
 */


/**
 * Queries Solr using a facet query.
 *
 * @param string $fieldname
 *   The name of the Solr field to query.
 * 
 * @return array|bool
 *   The results of the query, or FALSE if there are no results.
 */
function islandora_field_values_query_solr($fieldname) {
  $query_processor = new IslandoraSolrQueryProcessor();
  $query_processor->solrParams['facet'] = 'true';
  $query_processor->solrParams['facet.mincount'] = '0';
  $query_processor->solrParams['facet.limit'] = '1000000';
  $query_processor->solrParams['facet.field'] = $fieldname;
  $query_processor->solrLimit = '0';
  $query = '*:*';
  $query_processor->solrQuery = $query;
  $query_processor->executeQuery(FALSE);
  if ($query_processor->islandoraSolrResult['response']['numFound'] > 0) {
    return $query_processor->islandoraSolrResult['facet_counts']['facet_fields'][$fieldname];
  }
}

/**
 * Writes a tab-delimted output file, one value per row.
 *
 * Does not attempt handle multiline values.
 */
function islandora_field_values_write_output($results) {
  $fieldname = drush_get_option('fieldname');
  $num_results = count($results);
  $header = dt("Unique values for Solr field !fieldname (!count unique values)\n", array('!count' => $num_results, '!fieldname' => $fieldname));
  if (drush_get_option('output_file')) {
    $path = drush_get_option('output_file');
    file_put_contents($path, $header . PHP_EOL, FILE_APPEND);
    foreach ($results as $value => $count) {
      if (drush_get_option('remove_line_breaks')) {
        $field_value = str_replace(array("\r", "\n"), '', $value);
      }
      else {
        $field_value = $value;
      }
      $row = $field_value . "\t" . $count;
      file_put_contents($path, $row . PHP_EOL, FILE_APPEND);
    }
  }
}

