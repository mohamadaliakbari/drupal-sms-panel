<?php
// $Id$

/**
 * @file
 * Implements SMS Panel Bulk SMS resend link handler.
 */

require_once 'sms_panel_bulk_handler_field_sms_link.inc';

/**
 * Field handler to provide a link to delete a SMS message.
 */
class sms_panel_bulk_handler_field_sms_link_resend extends sms_panel_bulk_handler_field_sms_link {
  /**
   * Class constructor.
   */
  function construct() {
    parent::construct();
  }

  /**
   * Field renderer.
   */
  function render($values) {
    if (!user_access('send sms message')) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('resend');
    return l($text, 'admin/smsframework/panel/sms/' . $values->{$this->aliases['bid']} . '/resend', array(
      'query' => drupal_get_destination(),
    ));
  }
}

