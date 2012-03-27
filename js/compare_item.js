(function($)  {
	function comparefunction(context)  {
			var checkbox_id;
			var count = 0;
			var compare_count = 0;
			
			document.getElementById("btn_compare").disabled = true;
			
			$(".compare").live("click", function(){
				var checkbox_id = $(this).attr("id");
				$(this).attr("disabled", true);
				
				var item = document.getElementById("compare_item");
				item.id = checkbox_id;
				
				count++;
				compare_count++;
////alert($(".row-1 .col-1 .views-field .field-content img").attr("src"));
////				if ($(".row-1 .col-1 .views-field .field-content img")) {
////					alert($(".row-1 .col-1 .views-field .field-content img").attr("src"));
////				}
//				
//				if($.cookie("item-id") == null) {
//					$.cookie("item-id",checkbox_id);
//					alert("A cookie is now set"+$.cookie("item-id"));
//				}
				
				if (count == 4)	{
					$(":checkbox").attr("disabled", true);
				}
				btn_compare_check_enabled();
				
				$.ajax({
						type: "GET",
						url: Drupal.settings.basePath + '/compare_item_get_image',
						dataType: 'json',
						data: "id=" + encodeURI(checkbox_id),
						success: function(result){
					
					alert(result);

								
								var image_element = document.getElementById(item.id).getElementsByTagName("img");
								var span_element = document.getElementById(item.id).getElementsByTagName("span");
								image_element[0].setAttribute("src", result);
//								image_element[0].setAttribute("src", Drupal.settings.basePath + "sites/default/files/" + result);
								span_element[0].setAttribute("title", "Remove");
								span_element[0].innerHTML = "<img src='/compare/sites/all/modules/compare_item/images/remove.gif' />";
					}
				
				});
        
				$("#compare_cart").slideDown(500, function(){
					$(this).css("display", "static");
					$(this).css("position", "relative");
					$(this).css("top", "25%");
				});				
			});
			
			$(".remove_item").live('click', function(){
				$(this).hide("fast", function(){
					var id = $(this).parent().attr("id");
					var remove_item_id = document.getElementById(id);
					$("div#"+id).remove();
					
//					$.cookie("item-id",null);
					
					new_compare_item = $("<div/>");
					new_compare_item.attr("id", "compare_item");
					new_compare_item.attr("name", "compare_item");
					new_compare_item.addClass("div_image");
					new_compare_item.append($("<img/>")
							.addClass("image")
							.attr("src", "/compare/sites/all/modules/compare_item/images/add_item.jpg")
							.attr("height", 50)
							.attr("width", 50));
					
					new_compare_item.append($("<span/>")
							.addClass("remove_item")
							.click(function(){
								$(this).parent().remove();
							}));
              
					$("#compare_block").append(new_compare_item);
					
					$("input#"+id).attr("disabled", false);
					$("input#"+id).attr("checked", false);
					
					count--;
					compare_count--;
					
					btn_compare_check_enabled();
					$(":checkbox").each(function(){
						if (($(this).attr("checked")) == false){
							$(this).attr("disabled", false);
						}
					});
				});
			});
			
			function reset_compare_list(){
				count = 0;
				compare_count = 0;
				
//				$.cookie("item-id",null);
				
				$("[name='compare_item']").each(function(index){
					$(this).attr("id", "compare_item");
					$(this).children("img").attr("src", "/compare/sites/all/modules/compare_item/images/add_item.jpg");
					$(this).children("span").children("img").remove();
				});
				$(":disabled").attr("disabled", false);
				$(":checked").attr("checked", false);
			}
	
			$("#aclose").click(function(){
				reset_compare_list();
				btn_compare_check_enabled();
				$("#compare_cart").slideUp(100);
			});
			
			$("#aclearlist").click(function(){
				reset_compare_list();
				btn_compare_check_enabled();
			});
			
			function btn_compare_check_enabled(){
				if (compare_count >= 2) {
					document.getElementById("btn_compare").disabled = false;
				}
				else {
					document.getElementById("btn_compare").disabled = true;
				}
				return;
			}
	}
	
	Drupal.behaviors.compare = {
			attach: function(context)  {
				comparefunction(context);
			}
	};
})(jQuery);
