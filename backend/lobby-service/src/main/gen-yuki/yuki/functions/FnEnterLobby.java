package yuki.functions;

import io.vertx.core.json.JsonArray;
import yuki.framework.dataaccess.annotations.QueryDefinitionMetadata;
import yuki.framework.dataaccess.utils.QueryDefinition;

@QueryDefinitionMetadata(sql = " SELECT * FROM fn_enter_lobby( p_lobby_id := $1 ,p_player_id := $2 ,p_nickname := $3 ) ", returnType = JsonArray.class)
public interface FnEnterLobby extends QueryDefinition {

    void setP_lobby_id(Object p_lobby_id);

    void setP_player_id(Object p_player_id);

    void setP_nickname(Object p_nickname);
}
